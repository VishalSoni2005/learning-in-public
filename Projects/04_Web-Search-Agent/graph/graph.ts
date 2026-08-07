import { GraphState } from "./node-state.state";
import { StateGraph, START, END } from "@langchain/langgraph";
import { searchNode } from "../nodes/search.node";
import { filterNode } from "../nodes/filter.node";
import { analysisNode } from "../nodes/analyse.node";
import { summaryNode } from "../nodes/summarize.node";

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

export const webSearchAgent = graph.compile();
export const app = webSearchAgent;

