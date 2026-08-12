import { readdir, readFile, stat } from "node:fs/promises";
import { join, extname } from "node:path";
import { PDFParse } from "pdf-parse";

export interface Document {
  id: string;
  filename: string;
  content: string;
}

/**
 * Extracts raw text content from a PDF file using PDFParse.
 */
export async function extractPdfText(filePath: string): Promise<string> {
  const dataBuffer = await readFile(filePath);
  const parser = new PDFParse({ data: dataBuffer });
  try {
    const textResult = await parser.getText();
    return textResult.text ?? "";
  } finally {
    await parser.destroy();
  }
}

/**
 * Loads text (.txt) and PDF (.pdf) documents from a given directory.
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

    if (!fileStat.isFile()) {
      continue;
    }

    const ext = extname(filename).toLowerCase();
    let content = "";

    if (ext === ".txt") {
      content = await readFile(filePath, "utf-8");
    } else if (ext === ".pdf") {
      console.log(`\nExtracting text from PDF: ${filename}...`);
      content = await extractPdfText(filePath);
    } else {
      continue;
    }

    const trimmedContent = content.trim();

    if (trimmedContent.length > 0) {
      documents.push({
        id: filename,
        filename,
        content: trimmedContent,
      });
    } else {
      console.warn(`Warning: Could not extract text or file is empty: ${filename}`);
    }
  }

  return documents;
}
