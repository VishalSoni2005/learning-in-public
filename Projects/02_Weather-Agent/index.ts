import { ChatGroq } from "@langchain/groq";
import { ChatGoogleGenerativeAI } from "@langchain/google-genai";
import { createAgent } from "langchain";
import { weatherTool } from "./model-tools/weather-tool.js";
import { getMessages, saveMessage } from "./repository/message.repository.js";
import readline from "node:readline/promises";
import { stdin as input, stdout as output } from "node:process";
import dotenv from "dotenv";

dotenv.config({
  path: "../../.env",
});

let model: any;
if (process.env.GROQ_API_KEY) {
  model = new ChatGroq({
    apiKey: process.env.GROQ_API_KEY,
    model: "llama-3.1-8b-instant",
    temperature: 0,
  });
} else {
  model = new ChatGoogleGenerativeAI({
    apiKey: process.env.GOOGLE_API_KEY || "",
    model: "gemini-1.5-flash",
    temperature: 0,
  });
}

const agent = createAgent({
  model,
  tools: [weatherTool],
});

async function chatInThread(threadId: string, userPrompt: string) {
  // 1. Fetch previous messages from MongoDB
  const history = await getMessages(threadId);

  // 2. Build message context (only clean text content to keep payload light)
  const messages = [
    ...history.map((m) => ({
      role: m.role as "user" | "assistant",
      content: m.content,
    })),
    { role: "user", content: userPrompt },
  ];

  // 3. Save user prompt to MongoDB
  await saveMessage({ threadId, role: "user", content: userPrompt });

  // 4. Invoke agent
  const result = await agent.invoke({ messages });
  const aiResponse = String(
    result.messages.at(-1)?.content || "No response received.",
  );

  // 5. Save AI response to MongoDB
  await saveMessage({ threadId, role: "assistant", content: aiResponse });

  return aiResponse;
}

async function main() {
  const threadId = `weather_session_${Date.now()}`;
  console.log("\n==============================================");
  console.log("🌤️  AI Weather Assistant Started!");
  console.log(`📌 Session ID: ${threadId}`);
  console.log("==============================================\n");

  // Step 1: Default initial prompt comparing 3 cities
  const initialPrompt =
    "Compare the weather in Patna, Pune, and Purnia. Tell me which city is hottest and provide a quick breakdown.";
  console.log(`🤖 [Initial Query]: ${initialPrompt}`);
  console.log("⏳ Fetching weather data...\n");

  try {
    const initialReply = await chatInThread(threadId, initialPrompt);
    console.log(`AI 🤖:\n${initialReply}\n`);
  } catch (err: any) {
    console.error("❌ Error running initial query:", err.message);
  }

  // Step 2: Interactive Terminal Chat Loop
  const rl = readline.createInterface({ input, output });
  console.log("----------------------------------------------");
  console.log(
    "💬 Type your follow-up questions below (or type 'exit' or 'quit' to stop):\n",
  );

  try {
    while (true) {
      const userPrompt = await rl.question("You 👤: ");

      if (!userPrompt.trim()) continue;
      if (["exit", "quit", "q"].includes(userPrompt.trim().toLowerCase())) {
        console.log("\n👋 Exiting AI Weather Chat. Have a great day!");
        break;
      }

      console.log("⏳ Processing...\n");
      try {
        const reply = await chatInThread(threadId, userPrompt);
        console.log(`\nAI 🤖:\n${reply}\n`);
      } catch (err: any) {
        console.error("❌ Error:", err.message, "\n");
      }
    }
  } finally {
    rl.close();
    process.exit(0);
  }
}

main();
