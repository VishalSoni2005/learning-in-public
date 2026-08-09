/**
 * Computes manual Cosine Similarity between two vectors A and B.
 * Formula: cosine_similarity(A, B) = (A · B) / (||A|| × ||B||)
 */
export function cosineSimilarity(a: number[], b: number[]): number {
  if (a.length !== b.length) {
    throw new Error(
      `Vector dimension mismatch: vector A has length ${a.length}, but vector B has length ${b.length}.`
    );
  }

  if (a.length === 0) {
    throw new Error("Cannot compute cosine similarity for empty vectors.");
  }

  let dotProduct = 0;
  let magnitudeA = 0;
  let magnitudeB = 0;

  for (let i = 0; i < a.length; i++) {
    const valA = a[i]!;
    const valB = b[i]!;
    dotProduct += valA * valB;
    magnitudeA += valA * valA;
    magnitudeB += valB * valB;
  }

  const normA = Math.sqrt(magnitudeA);
  const normB = Math.sqrt(magnitudeB);

  if (normA === 0 || normB === 0) {
    return 0;
  }

  return dotProduct / (normA * normB);
}
