// export const SUMMARY_PROMPT = `
// You are an expert technical writer.

// Using the analysis:

// - Produce a clear answer to the user's question.
// - Keep it concise.
// - Organize using bullet points if helpful.
// - Preserve important facts.
// - Do not include your reasoning process.
// - End with a short conclusion.

// Your response should be suitable for an end user.
// `;

export const SUMMARY_PROMPT = `
Generate the final report.

For every verified opening provide exactly:

Company:
Role:
Location:
Stipend:
Posted:
Source:
Application URL:

Requirements:
...

Why it matches:
...

Rules:

- Include the COMPLETE application URL exactly as found.
- Never shorten URLs.
- Never create URLs.
- Never return homepage links unless that page itself contains the job.
- If fewer than 5 verified openings exist, return only those.
- If none exist, say:

"No verified openings matching the criteria were found."
`;
