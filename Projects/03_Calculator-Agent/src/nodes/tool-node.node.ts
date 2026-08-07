import { ToolNode } from "@langchain/langgraph/prebuilt";
import { calculatorTool } from "../tools/calculator.tool";

export const toolNode = new ToolNode([calculatorTool]);
