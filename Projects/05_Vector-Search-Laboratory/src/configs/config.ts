export const config = {
  embedding: {
    model: "Xenova/all-MiniLM-L6-v2",
    dimensions: 384,
  },

  chroma: {
    host: "localhost",
    port: 8000,
    collectionName: "knowledge_base",
  },

  chunking: {
    chunkSize: 500,
    chunkOverlap: 50,
  },

  search: {
    defaultTopK: 5,
  },
} as const;
