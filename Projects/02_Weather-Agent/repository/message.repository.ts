import { connectMongoDB } from "../utils/mongo-client.js";

export async function saveMessage(message: {
  threadId: string;
  role: string;
  content: string;
}) {
  const db = await connectMongoDB();

  return db.collection("messages").insertOne({
    ...message,
    createdAt: new Date(),
  });
}

export async function getMessages(threadId: string) {
  const db = await connectMongoDB();

  return db
    .collection("messages")
    .find({ threadId })
    .sort({ createdAt: 1 })
    .toArray();
}
