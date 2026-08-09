export interface Chunk {
  id: string;
  documentId: string;
  chunkIndex: number;
  text: string;
  startOffset: number;
  endOffset: number;
}

export interface ChunkOptions {
  chunkSize: number;
  chunkOverlap: number;
}

/**
 * Splits text into chunks with configurable chunkSize and chunkOverlap.
 * Enforces invalid configuration rules:
 * - chunkSize > 0
 * - chunkOverlap >= 0
 * - chunkOverlap < chunkSize
 */
export function chunkText(
  text: string,
  documentId: string,
  options: ChunkOptions
): Chunk[] {
  const { chunkSize, chunkOverlap } = options;

  if (chunkSize <= 0) {
    throw new Error("chunkSize must be greater than 0");
  }

  if (chunkOverlap < 0) {
    throw new Error("chunkOverlap must be non-negative");
  }

  if (chunkOverlap >= chunkSize) {
    throw new Error(
      `Invalid chunk configuration: chunkOverlap (${chunkOverlap}) must be strictly less than chunkSize (${chunkSize}).`
    );
  }

  const trimmedText = text.trim();
  if (!trimmedText) {
    return [];
  }

  const chunks: Chunk[] = [];
  const step = chunkSize - chunkOverlap;
  let chunkIndex = 0;

  for (let start = 0; start < text.length; start += step) {
    const end = Math.min(start + chunkSize, text.length);
    const chunkContent = text.slice(start, end).trim();

    if (chunkContent.length > 0) {
      chunks.push({
        id: `${documentId}_chunk_${chunkIndex}`,
        documentId,
        chunkIndex,
        text: chunkContent,
        startOffset: start,
        endOffset: end,
      });
      chunkIndex++;
    }

    if (end === text.length) {
      break;
    }
  }

  return chunks;
}
