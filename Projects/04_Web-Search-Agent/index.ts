import "dotenv/config";

import { app } from "./graph/graph";
// import { SEARCH_PROMPT } from "./prompts/search";

const SEARCH_PROMPT = `Find verified AI Full Stack internships in Pune, India.

Search only official company career pages, Naukri, Wellfound, LinkedIn Jobs, Greenhouse, Lever, Ashby, Workday, and Indeed.

Requirements:
- Internship only
- AI Full Stack, GenAI Engineer, LLM Engineer, AI Software Engineer or Full Stack Developer (AI)
- Posted within the last 2 days
- Stipend above ₹20,000/month
- Currently accepting applications

For every verified opening include:
- Company
- Job title
- Location
- Stipend
- Posted date
- Required skills
- Direct application URL
- Source website

Reject any opening that:
- cannot be verified,
- has no direct job page,
- has an expired application,
- has missing or conflicting information.

Do not invent companies, jobs, salaries, dates or URLs.

If fewer than five verified openings exist, return only those and explain why.`;

async function main() {
  try {
    const result = await app.invoke({
      query: SEARCH_PROMPT,
    });

    console.log("\n========== FINAL ANSWER ==========\n");

    // console.log(result.summary);
    console.log("Query:");
    console.log(result.query);

    console.log("\nSearch Results:");
    console.log(result.searchResults);

    console.log("\nFiltered Results:");
    console.log(result.filteredResults);

    console.log("\nAnalysis:");
    console.log(result.analysis);

    console.log("\nSummary:");
    console.log(result.summary);

    console.log("\n==================================");
  } catch (error) {
    console.error(error);
  }
}

main();
