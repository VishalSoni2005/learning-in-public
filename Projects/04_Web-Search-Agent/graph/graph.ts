import { GraphState } from "./node-state.state";
import { StateGraph, START, END, MemorySaver } from "@langchain/langgraph";
import { searchNode } from "../nodes/search.node";
import { filterNode } from "../nodes/filter.node";
import { analysisNode } from "../nodes/analyse.node";
import { summaryNode } from "../nodes/summarize.node";

// Checkpointer for persisting graph state between interrupts (Human-in-the-Loop)
export const checkpointer = new MemorySaver();

const graph = new StateGraph(GraphState)
  .addNode("search", searchNode)
  .addNode("filter", filterNode)
  .addNode("analyse", analysisNode)
  .addNode("summarize", summaryNode)

  .addEdge(START, "search")
  .addEdge("search", "filter")
  .addEdge("filter", "analyse")
  .addEdge("analyse", "summarize")
  .addEdge("summarize", END);

// Compile graph with checkpointer and interrupts after each step for Human-in-the-Loop review
export const webSearchAgent = graph.compile({
  checkpointer,
  interruptAfter: ["search", "filter", "analyse"],
});

export const app = webSearchAgent;
