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
