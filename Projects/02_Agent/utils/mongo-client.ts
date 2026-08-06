import { Db, MongoClient } from "mongodb";
import dotenv from "dotenv";
dotenv.config({
  path: "../../.env",
});

const MONGO_URI = process.env.MONGO_URI || "mongodb://localhost:27017/";
const DATABASE_NAME = "agentic-ai-learning";

let db: Db;
let client: MongoClient;

export const connectMongoDB = async () => {
  if (db) return db;

  try {
    client = new MongoClient(MONGO_URI);
    await client.connect();
    db = client.db(DATABASE_NAME);
    console.info(`[MONGO-CLIENT] 🟢 Connected to "${DATABASE_NAME}" MongoDB`);
    return db;
  } catch (error) {
    console.error("[MONGO-CLIENT] 🟥 MongoDB connection failed:", error);
    throw error;
  }
};
