import { indexDocuments } from "../search/index.service.js";
import { embeddingService } from "../embeddings/embedding.service.js";
import { cosineSimilarity } from "../utils/cosine.js";
import { config } from "../configs/config.js";
import { search } from "../search/search.service.js";

const [, , command, ...args] = process.argv; // * this is handle as pnpm run dev <string>

async function main() {
  // todo: comment it and fetch it from pmpm cli
  // const command: any = "embed";
  // const args = ["hello hello hello"];

  switch (command) {
    case "index": {
      const directory = args[0];

      if (!directory) {
        console.error("Error: Directory path is required.");
        console.error("Usage: pnpm dev index ./data/documents");
        process.exit(1);
      }

      await indexDocuments(directory);
      return;
      // break;
    }

    case "search": {""
      let topK: number = config.search.defaultTopK;
      const queryParts: string[] = [];

      for (let i = 0; i < args.length; i++) {
        const arg = args[i]!;
        if (arg === "--top-k" || arg === "-k") {
          const val = Number(args[i + 1]);
          if (!isNaN(val) && val > 0) {
            topK = val;
            i++;
          }
        } else if (arg.startsWith("--top-k=")) {
          const val = Number(arg.split("=")[1]);
          if (!isNaN(val) && val > 0) {
            topK = val;
          }
        } else {
          queryParts.push(arg);
        }
      }

      const query = queryParts.join(" ");

      if (!query || query.trim().length === 0) {
        console.error("Error: Search query is required.");
        console.error('Usage: pnpm dev search "your query" [--top-k 5]');
        process.exit(1);
      }

      console.log(`Searching for: "${query}" (topK=${topK})`);
      const results = await search(query, topK);

      if (results.length === 0) {
        console.log("No matching results found.");
        break;
      }

      console.log(`\nSearch results (${results.length}):\n`);

      results.forEach((result) => {
        console.log(`────────────────────────────`);
        console.log(`#${result.rank}`);
        console.log(`ID: ${result.id}`);
        console.log(`Cosine Distance: ${result.distance.toFixed(4)}`);
        console.log(`Cosine Similarity: ${result.similarity.toFixed(4)}`);
        console.log(`Source: ${result.metadata?.source ?? "N/A"}`);
        console.log(`Chunk Index: ${result.metadata?.chunkIndex ?? "N/A"}`);
        console.log(`\nText:\n${result.document}`);
      });

      // break;
      return;
    }

    case "embed": {
      const text = args.join(" ");

      if (!text || text.trim().length === 0) {
        console.error("Error: Text input is required.");
        console.error('Usage: pnpm dev embed "car"');
        process.exit(1);
      }

      console.log(`Generating embedding for: "${text}"`);
      const vector = await embeddingService.embed(text);

      console.log(`✓ Embedding generated successfully`);
      console.log(`Dimensions: ${vector.length}`);
      console.log(
        `Sample values (first 5): [${vector
          .slice(0, 5)
          .map((v) => v.toFixed(6))
          .join(", ")}...]`,
      );
      return;
      // break;
    }

    case "similarity": {
      const text1 = args[0];
      const text2 = args[1];

      if (!text1 || !text2) {
        console.error("Error: Two text arguments are required.");
        console.error('Usage: pnpm dev similarity "car" "automobile"');
        process.exit(1);
      }

      console.log(`Computing similarity between:`);
      console.log(`  Text 1: "${text1}"`);
      console.log(`  Text 2: "${text2}"`);

      const vec1 = await embeddingService.embed(text1);
      const vec2 = await embeddingService.embed(text2);

      const sim = cosineSimilarity(vec1, vec2);
      const distance = 1 - sim;

      console.log(`\nResults:`);
      console.log(`────────────────────────────`);
      console.log(`Cosine Similarity: ${sim.toFixed(6)}`);
      console.log(`Cosine Distance:   ${distance.toFixed(6)}`);
      // break;
      return;
    }

    default:
      console.log(`
🔬 Vector Search Laboratory CLI

Usage:
  pnpm dev index <directory>                Index documents in a directory
  pnpm dev search "<query>" [--top-k N]     Perform semantic similarity search
  pnpm dev embed "<text>"                   Generate embedding vector and verify dimensions
  pnpm dev similarity "<text1>" "<text2>"   Compute manual cosine similarity between two texts

Examples:
  pnpm dev index ./data/documents
  pnpm dev search "how does TCP provide reliable communication" --top-k 3
  pnpm dev embed "car"
  pnpm dev similarity "car" "automobile"
      `);
      if (command && command !== "--help" && command !== "-h") {
        console.error(`\nUnknown command: "${command}"`);
        process.exit(1);
      }
  }
}

main().catch((error) => {
  console.error(
    "\nAn error occurred:",
    error instanceof Error ? error.message : error,
  );
  process.exit(1);
});
