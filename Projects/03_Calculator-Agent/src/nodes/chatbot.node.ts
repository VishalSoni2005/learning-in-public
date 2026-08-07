import model from "../llm";

export async function chatbot(state: any) {
  const response = await model.invoke(state.messages);

  return {
    messages: [response],
  };
}
