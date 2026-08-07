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
import { SUMMARY_PROMPT } from "../prompts";
import { GraphState } from "../graph/node-state.state";

export const summaryNode = async (state: typeof GraphState.State) => {
  try {
    const { query, analysis, humanFeedback } = state;

    const userMessageContent = [
      `User Question:\n${query}`,
      humanFeedback ? `\nHuman Feedback / Directives:\n${humanFeedback}` : "",
      `\nAnalytical Report:\n${analysis}`,
    ]
      .filter(Boolean)
      .join("\n");

    const response = await model.invoke([
      {
        role: "system",
        content: SUMMARY_PROMPT,
      },
      {
        role: "user",
        content: userMessageContent,
      },
    ]);

    return {
      summary: response.text,
    };
  } catch (error) {
    console.error("Summary node failed: ", error);
    return { summary: "" };
  }
};
