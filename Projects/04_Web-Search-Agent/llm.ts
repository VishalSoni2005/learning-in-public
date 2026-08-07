import { ChatGroq } from "@langchain/groq";
import { ChatGoogleGenerativeAI } from "@langchain/google-genai";
import dotenv from "dotenv";

dotenv.config({
  path: "../../.env",
});

const grok_key = process.env.GROQ_API_KEY || "";
const google_key = process.env.GOOGLE_API_KEY || "";

let model: any;
if (grok_key) {
  model = new ChatGroq({
    apiKey: grok_key,
    model: "llama-3.1-8b-instant",
    temperature: 0,
  });
} else if (google_key) {
  model = new ChatGoogleGenerativeAI({
    apiKey: google_key,
    model: "gemini-1.5-flash",
    temperature: 0,
  });
} else {
  throw new Error("No API key found");
}

export default model;
