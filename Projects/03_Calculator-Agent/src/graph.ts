import { StateGraph, START, END } from "@langchain/langgraph";
import { toolsCondition } from "@langchain/langgraph/prebuilt";

import { CalculatorState } from "./states/state";

import { chatbot } from "./nodes/chatbot.node";
import { toolNode } from "./nodes/tool-node.node";

const graph = new StateGraph(CalculatorState)
  .addNode("chatbot", chatbot)
  .addNode("tools", toolNode)
  .addEdge(START, "chatbot")
  .addConditionalEdges("chatbot", toolsCondition)
  .addEdge("tools", "chatbot")
  .addEdge("chatbot", END);

export const app = graph.compile();


// import {
//   StateGraph,
//   Annotation,
//   MessagesAnnotation,
//   END,
// } from "@langchain/langgraph";
// import { ChatAnthropic } from "@langchain/anthropic";
// import { SystemMessage, HumanMessage } from "langchain";

// const model = new ChatAnthropic({ model: "claude-haiku-4-5" });

// const PipelineState = Annotation.Root({
//   ...MessagesAnnotation.spec,
//   classification: Annotation<string>({
//     reducer: (_, b) => b,
//     default: () => "",
//   }),
//   research: Annotation<string>({ reducer: (_, b) => b, default: () => "" }),
//   analysis: Annotation<string>({ reducer: (_, b) => b, default: () => "" }),
//   synthesis: Annotation<string>({ reducer: (_, b) => b, default: () => "" }),
// });

// type PipelineStateType = typeof PipelineState.State;

// function createPipelineStepSubgraph(
//   run: (state: PipelineStateType) => Promise<Partial<PipelineStateType>>,
// ) {
//   return new StateGraph(PipelineState)
//     .addNode("run", run)
//     .addEdge("__start__", "run")
//     .compile();
// }

// const classifySubgraph = createPipelineStepSubgraph(async (state) => {
//   const response = await model.invoke([
//     new SystemMessage(
//       "Classify the user request into one of: comparison, explanation, creative, analytical. Reply with just the category.",
//     ),
//     ...state.messages,
//   ]);
//   const content = typeof response.content === "string" ? response.content : "";
//   return { classification: content.toLowerCase().trim() };
// });

// const doResearchSubgraph = createPipelineStepSubgraph(async (state) => {
//   const response = await model.invoke([
//     new SystemMessage(
//       "You are a researcher. Gather key facts and information related to the user's request. Be concise but thorough.",
//     ),
//     ...state.messages,
//   ]);
//   return {
//     research: typeof response.content === "string" ? response.content : "",
//   };
// });

// const analyzeSubgraph = createPipelineStepSubgraph(async (state) => {
//   const response = await model.invoke([
//     new SystemMessage(
//       "You are an analyst. Based on the research, identify key insights, patterns, and conclusions.",
//     ),
//     new HumanMessage(`Research findings:\n${state.research}`),
//   ]);
//   return {
//     analysis: typeof response.content === "string" ? response.content : "",
//   };
// });

// const synthesizeSubgraph = createPipelineStepSubgraph(async (state) => {
//   const response = await model.invoke([
//     new SystemMessage(
//       "Synthesize the analysis into a clear, well-structured response for the user.",
//     ),
//     new HumanMessage(
//       `Classification: ${state.classification}\nAnalysis:\n${state.analysis}`,
//     ),
//   ]);
//   return {
//     synthesis: typeof response.content === "string" ? response.content : "",
//     messages: [response],
//   };
// });

// export const graph = new StateGraph(PipelineState)
//   .addNode("classify", classifySubgraph, { subgraphs: [classifySubgraph] })
//   .addNode("do_research", doResearchSubgraph, {
//     subgraphs: [doResearchSubgraph],
//   })
//   .addNode("analyze", analyzeSubgraph, { subgraphs: [analyzeSubgraph] })
//   .addNode("synthesize", synthesizeSubgraph, {
//     subgraphs: [synthesizeSubgraph],
//   })
//   .addEdge("__start__", "classify")
//   .addEdge("classify", "do_research")
//   .addEdge("do_research", "analyze")
//   .addEdge("analyze", "synthesize")
//   .addEdge("synthesize", END)
//   .compile();
