import "./cli/index.js";

export { embeddingService } from "./embeddings/embedding.service.js";
export { loadDocuments } from "./documents/loader.js";
export { chunkText } from "./documents/chunker.js";
export { cosineSimilarity } from "./utils/cosine.js";
export { search } from "./search/search.service.js";
export { indexDocuments } from "./search/index.service.js";
export { getCollection } from "./vector-db/chroma.js";
