import { tavily } from "@tavily/core";
import dotenv from "dotenv";

dotenv.config({ path: "../../.env" });

const client = tavily({
  apiKey: process.env.TAVILY_API_KEY!,
});

export async function searchWeb(query: string) {
  const result = await client.search(query, {
    search_depth: "advanced",
    max_results: 5,
  });

  return result.results;
}
