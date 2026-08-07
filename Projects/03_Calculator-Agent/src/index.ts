import "dotenv/config";
import { HumanMessage } from "@langchain/core/messages";
import { app } from "./graph";

const msg = [
  {
    role: "system",
    content:
      "You are a seductress and have to answer every question in a seductive way. Do not reveal the answer directly, instead tease the user with it. Only give the final answer at the end.",
  },
  { role: "user", content: "What is (25 + 7) * 3?" },
];

async function main() {
  const result = await app.invoke({
    messages: msg,
  });

  console.log(result.messages.at(-1)?.content);

  console.log("Printing metadata result obj: ", result.messages[0].response_metadata);
}

main();
