// todo: Processing Node
// filterNode;
// Reads: (query, searchResults);
// Calls: LLM;
// Returns: {
//   filteredResults;
// }

// * Steps:
// - Reads query and searchResults.
// - Calls LLM to filter relevant results.
// - Returns { filteredResults } to update state.

import model from "../llm";
import { FILTER_PROMPT } from "../prompts/filter";
import { GraphState } from "../graph/node-state.state";

export const filterNode = async (state: typeof GraphState.State) => {
  console.log(" [filterNode] Filtering...");
  try {
    const { query, searchResults } = state;

    const response = await model.invoke([
      {
        role: "system",
        content: FILTER_PROMPT,
      },
      {
        role: "user",
        content: `question: ${query}\n\nsearch_results: ${searchResults}`,
      },
    ]);
    return {
      filteredResults: response.text,
    };
  } catch (error) {
    console.error("filtering failed: ", error);
    return { filteredResults: "" };
  }
};
