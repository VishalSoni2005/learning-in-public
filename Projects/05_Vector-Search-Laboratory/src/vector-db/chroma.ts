import { ChromaClient } from "chromadb";
import { config } from "../configs/config.js";

const client = new ChromaClient({
  host: config.chroma.host,
  port: config.chroma.port,
  ssl: false,
});

export async function getCollection() {
  const sanitizedModelName = config.embedding.model.replace(/[^a-zA-Z0-9_-]/g, "_");
  const collectionName = `${config.chroma.collectionName}_${sanitizedModelName}`;

  return client.getOrCreateCollection({
    name: collectionName,
    metadata: { "hnsw:space": "cosine" },
    embeddingFunction: {
      name: "local-transformers",
      generate: async (texts: string[]) => [],
    },
  });
}

export { client };
