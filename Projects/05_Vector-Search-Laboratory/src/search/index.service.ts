import { loadDocuments } from "../documents/loader.js";
import { chunkText } from "../documents/chunker.js";
import { embeddingService } from "../embeddings/embedding.service.js";
import { getCollection } from "../vector-db/chroma.js";
import { config } from "../configs/config.js";

export async function indexDocuments(directory: string) {
  console.log(`Loading documents from: ${directory}`);

  const documents = await loadDocuments(directory);

  if (documents.length === 0) {
    console.log("No .txt documents found in the specified directory.");
    return;
  }

  console.log(`Found ${documents.length} document(s).`);

  const collection = await getCollection();
  let totalChunksStored = 0;

  for (const document of documents) {
    console.log(`\nIndexing: ${document.filename}`);

    const chunks = chunkText(document.content, document.id, config.chunking);

    if (chunks.length === 0) {
      console.log(`Skipping ${document.filename}: empty or no valid text chunks.`);
      continue;
    }

    console.log(`Created ${chunks.length} chunk(s).`);

    const embeddings = await embeddingService.embedMany(
      chunks.map((chunk) => chunk.text)
    );

    await collection.upsert({
      ids: chunks.map((chunk) => chunk.id),
      documents: chunks.map((chunk) => chunk.text),
      embeddings,
      metadatas: chunks.map((chunk) => ({
        source: document.filename,
        chunkIndex: chunk.chunkIndex,
        startOffset: chunk.startOffset,
        endOffset: chunk.endOffset,
      })),
    });

    totalChunksStored += chunks.length;
    console.log(`Stored ${chunks.length} vector(s) in Chroma.`);
  }

  const count = await collection.count();
  console.log(`\nTotal vectors stored in Chroma collection: ${count}`);
}
