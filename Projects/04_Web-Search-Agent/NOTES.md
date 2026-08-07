## State Management

- State is the information that needs to be passed from one node to the next.

## Annotation vs MessagesAnnotation

### What is MessagesAnnotation?

- MessagesAnnotation is a prebuilt state that already includes a messages field with the correct reducer for accumulating chat history.

- If you are building a chatbot or any application that needs to maintain a conversation history, MessagesAnnotation is the best choice.

### What is Annotation?

- You define every state field yourself.

Example:

const GraphState = Annotation.Root({
query: Annotation<string>(),
searchResults: Annotation<string[]>(),
summary: Annotation<string>(),
});

- Annotation is a more flexible way to define custom state schemas for your LangGraph applications.

- If you are building a custom application that needs to maintain a complex state, Annotation is the best choice.
