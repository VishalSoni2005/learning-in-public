import { Annotation } from "@langchain/langgraph";

// ! The state should contain only the information that needs to be passed from one node to the next.
// ? Annotation<T>({ reducer, default }):  Annotation is used to define the schema of the state. It takes two arguments, reducer and default.

// ? Reducers become useful when multiple nodes write to the same field (for example, parallel searches that all append to searchResults). Since your graph is a simple linear pipeline (search → filter → analyze → summarize), you can keep the state simpler for now and introduce reducers later when you explore branching or parallel execution.

// * Initial State
// {
//   query: "What are the latest AI trends?",
//   searchResults: [],
//   filteredResults: [],
//   analysis: "",
//   summary: ""
// }

export const GraphState = Annotation.Root({
  // ...MessagesAnnotation.spec, // * not needed as we have fixed workflow
  // User's question
  query: Annotation<string>(),

  // Raw search results from Tavily
  searchResults: Annotation<string[]>(),

  // Relevant results after filtering
  filteredResults: Annotation<string>(),

  // LLM analysis of filtered results
  analysis: Annotation<string>(),

  // Final response
  summary: Annotation<string>(),
});

// export const NodeState = {
//   query: z.string(),
//   searchResults: z.array(z.string()),
//   filterResults: z.array(z.string()),
//   analysedResult: z.string(),
//   finalAnswer: z.string(),
// };
