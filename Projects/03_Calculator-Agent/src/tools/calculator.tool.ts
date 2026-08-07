import { tool } from "@langchain/core/tools";
import { z } from "zod";

export const calculatorTool = tool(
  async ({ expression }) => {
    const result = eval(expression);

    return result.toString();
  },
  {
    name: "calculator",

    description: "Evaluate mathematical expressions.",

    schema: z.object({
      expression: z.string(),
    }),
  },
);
