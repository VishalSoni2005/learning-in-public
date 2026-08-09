import {
  pipeline,
  type FeatureExtractionPipeline,
} from "@huggingface/transformers";
import { config } from "../configs/config.js";

export class EmbeddingService {
  private extractor: FeatureExtractionPipeline | null = null;

  private async getExtractor(): Promise<FeatureExtractionPipeline> {
    if (!this.extractor) {
      console.log(`Loading embedding model (${config.embedding.model})...`);
      this.extractor = await pipeline(
        "feature-extraction",
        config.embedding.model
      );
      console.log("Embedding model loaded.");
    }
    return this.extractor;
  }

  /**
   * Generates a 384-dimensional embedding vector for a single text input.
   */
  async embed(text: string): Promise<number[]> {
    if (!text || text.trim().length === 0) {
      throw new Error("Cannot generate embedding for empty text.");
    }

    const extractor = await this.getExtractor();
    const output = await extractor(text, {
      pooling: "mean",
      normalize: true,
    });

    const vector = Array.from(output.data as Float32Array);

    if (vector.length !== config.embedding.dimensions) {
      throw new Error(
        `Embedding dimension mismatch: expected ${config.embedding.dimensions}, got ${vector.length}`
      );
    }

    return vector;
  }

  /**
   * Generates 384-dimensional embedding vectors for an array of texts.
   */
  async embedMany(texts: string[]): Promise<number[][]> {
    if (texts.length === 0) {
      return [];
    }

    const extractor = await this.getExtractor();
    const output = await extractor(texts, {
      pooling: "mean",
      normalize: true,
    });

    const vectors = output.tolist() as number[][];

    for (let i = 0; i < vectors.length; i++) {
      const vec = vectors[i];
      if (!vec || vec.length !== config.embedding.dimensions) {
        throw new Error(
          `Embedding dimension mismatch at index ${i}: expected ${config.embedding.dimensions}, got ${vec?.length ?? 0}`
        );
      }
    }

    return vectors;
  }
}

export const embeddingService = new EmbeddingService();
