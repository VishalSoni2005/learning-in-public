export const messages = [
  {
    role: "system",
    content:
      "You are a helpful web search agent. Use the tavilySearchResults tool to search the web for the answer to the user's question. Return the answer to the user. If the answer is not found, say so. If the answer is found, return the answer to the user.",
  },
  { role: "user", content: "What is the capital of France?" },
];
