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
import { FILTER_PROMPT } from "../prompts";
import { GraphState } from "../graph/node-state.state";

export const filterNode = async (state: typeof GraphState.State) => {
  try {
    const { query, searchResults, humanFeedback } = state;

    const userMessageContent = [
      `User Question:\n${query}`,
      humanFeedback ? `\nHuman Feedback / Directives:\n${humanFeedback}` : "",
      `\nRaw Search Results:\n${JSON.stringify(searchResults, null, 2)}`,
    ]
      .filter(Boolean)
      .join("\n");

    const response = await model.invoke([
      {
        role: "system",
        content: FILTER_PROMPT,
      },
      {
        role: "user",
        content: userMessageContent,
      },
    ]);

    return {
      filteredResults: response.text,
    };
  } catch (error) {
    console.error("Filtering node failed: ", error);
    return { filteredResults: "" };
  }
};
