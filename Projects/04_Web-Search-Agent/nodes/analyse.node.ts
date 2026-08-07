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
import { ANALYSIS_PROMPT } from "../prompts/analysis";
import { GraphState } from "../graph/node-state.state";

export const analysisNode = async (state: typeof GraphState.State) => {
  console.log(" [analysisNode] Analyzing...");
  try {
    const { query, filteredResults } = state;

    const response = await model.invoke([
      {
        role: "system",
        content: ANALYSIS_PROMPT,
      },
      {
        role: "user",
        content: `
Question:

${query}

Filtered Results:

${filteredResults}
`,
      },
    ]);

    return {
      analysis: response.text,
    };
  } catch (error) {
    console.error("filtering failed: ", error);
    return { analysis: "" };
  }
};
