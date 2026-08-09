import { embeddingService } from "../embeddings/embedding.service.js";
import { getCollection } from "../vector-db/chroma.js";
import { config } from "../configs/config.js";

export interface SearchResult {
  rank: number;
  id: string;
  document: string;
  distance: number;
  similarity: number;
  metadata: Record<string, unknown> | null;
}

export async function search(
  query: string,
  topK: number = config.search.defaultTopK
): Promise<SearchResult[]> {
  if (!query || query.trim().length === 0) {
    throw new Error("Search query cannot be empty.");
  }

  if (topK <= 0) {
    throw new Error("topK must be a positive integer.");
  }

  const collection = await getCollection();
  const queryEmbedding = await embeddingService.embed(query);

  const results = await collection.query({
    queryEmbeddings: [queryEmbedding],
    nResults: topK,
    include: ["documents", "metadatas", "distances"],
  });

  const ids = results.ids[0] ?? [];
  const documents = results.documents[0] ?? [];
  const distances = results.distances?.[0] ?? [];
  const metadatas = results.metadatas?.[0] ?? [];

  return ids.map((id, index) => {
    const dist = distances[index] ?? 0;
    // Cosine similarity for normalized vectors: 1 - cosine_distance
    const sim = 1 - dist;

    return {
      rank: index + 1,
      id,
      document: documents[index] ?? "",
      distance: dist,
      similarity: sim,
      metadata: (metadatas[index] as Record<string, unknown> | null) ?? null,
    };
  });
}
