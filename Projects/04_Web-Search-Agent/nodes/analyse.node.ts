// todo: Processing Node
// analysisNode;
// Reads: (query, filteredResults);
// Calls: LLM;
// Returns: {
//   analysis;
// }

// * Steps:
// - Takes state (query and filteredResults).
// - Calls LLM to analyze and extract insights.
// - Returns { analysis } to update state.
import model from "../llm";
import { ANALYSIS_PROMPT } from "../prompts";
import { GraphState } from "../graph/node-state.state";

export const analysisNode = async (state: typeof GraphState.State) => {
  try {
    const { query, filteredResults, humanFeedback } = state;

    const userMessageContent = [
      `User Question:\n${query}`,
      humanFeedback ? `\nHuman Feedback / Directives:\n${humanFeedback}` : "",
      `\nFiltered Search Results:\n${filteredResults}`,
    ]
      .filter(Boolean)
      .join("\n");

    const response = await model.invoke([
      {
        role: "system",
        content: ANALYSIS_PROMPT,
      },
      {
        role: "user",
        content: userMessageContent,
      },
    ]);

    return {
      analysis: response.text,
    };
  } catch (error) {
    console.error("Analysis node failed: ", error);
    return { analysis: "" };
  }
};
