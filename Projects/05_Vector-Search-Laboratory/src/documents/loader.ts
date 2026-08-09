import { readdir, readFile, stat } from "node:fs/promises";
import { join, extname } from "node:path";

export interface Document {
  id: string;
  filename: string;
  content: string;
}

/**
 * Loads text (.txt) documents from a given directory.
 */
export async function loadDocuments(directory: string): Promise<Document[]> {
  try {
    const stats = await stat(directory);
    if (!stats.isDirectory()) {
      throw new Error(`Path '${directory}' is not a directory.`);
    }
  } catch (err: unknown) {
    if ((err as { code?: string }).code === "ENOENT") {
      throw new Error(`Directory not found: '${directory}'`);
    }
    throw err;
  }

  const files = await readdir(directory);
  const documents: Document[] = [];

  for (const filename of files) {
    const filePath = join(directory, filename);
    const fileStat = await stat(filePath);

    if (!fileStat.isFile() || extname(filename) !== ".txt") {
      continue;
    }

    const content = await readFile(filePath, "utf-8");

    documents.push({
      id: filename,
      filename,
      content,
    });
  }

  return documents;
}
