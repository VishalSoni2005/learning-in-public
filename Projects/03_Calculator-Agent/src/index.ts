import "dotenv/config";

import { HumanMessage } from "@langchain/core/messages";

import { app } from "./graph";


async function main() {
  const result = await app.invoke({
    messages: [new HumanMessage("What is (25 + 7) * 3?")],
  });

  console.log(result.messages.at(-1)?.content);
}

main();
