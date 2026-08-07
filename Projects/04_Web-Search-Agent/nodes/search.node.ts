// todo: Initial Node
// searchNode;
// Responsibilities:
// - Reads: query;
// - Calls: Tavily;
// - Returns: {
//   searchResults;
// }

import { GraphState } from "../graph/node-state.state";
import { searchWeb } from "../tools/web-search.tool";

// * Steps:
// - Takes state as input (which must include query).
// - Calls tavily.search().
// - Returns { searchResults } to update state.

export const searchNode = async (state: typeof GraphState.State) => {
  try {
    const { query } = state;
    console.log(" [searchNode] Query: ", query);
    const searchResults = await searchWeb(query);
    return { searchResults: searchResults.map((result) => result.content) };
  } catch (error) {
    console.error("Search failed:", error);
    return { searchResults: "" };
  }
};
