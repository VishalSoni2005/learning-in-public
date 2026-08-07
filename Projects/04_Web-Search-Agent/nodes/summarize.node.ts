// summaryNode;
// Reads: (query, analysis);
// Calls: LLM;
// Returns: {
//   summary;
// }

// * Steps:
// - Takes state as input (which must include query and analysis).
// - Calls LLM to summarize.
// - Returns { summary } to update state.
import model from "../llm";
import { SUMMARY_PROMPT } from "../prompts/summary";
import { GraphState } from "../graph/node-state.state";

export const summaryNode = async (state: typeof GraphState.State) => {
  try {
    const { query, analysis } = state;

    const response = await model.invoke([
      {
        role: "system",
        content: SUMMARY_PROMPT,
      },
      {
        role: "user",
        content: state.analysis,
      },
    ]);

    return {
      summary: response.text,
    };
  } catch (error) {
    console.error("Summary failed: ", error);
    return { summary: "" };
  }
};
