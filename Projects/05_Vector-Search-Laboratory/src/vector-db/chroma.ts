import { ChromaClient } from "chromadb";
import { config } from "../configs/config.js";

const client = new ChromaClient({
  path: `http://${config.chroma.host}:${config.chroma.port}`,
});

export async function getCollection() {
  const sanitizedModelName = config.embedding.model.replace(/[^a-zA-Z0-9_-]/g, "_");
  const collectionName = `${config.chroma.collectionName}_${sanitizedModelName}`;

  return client.getOrCreateCollection({
    name: collectionName,
    metadata: { "hnsw:space": "cosine" },
    embeddingFunction: {
      generate: async (texts: string[]) => {
        throw new Error("Default embedding function called unexpectedly. Use local EmbeddingService instead.");
      },
    },
  });
}

export { client };
