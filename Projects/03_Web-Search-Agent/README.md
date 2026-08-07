search → filter → analyze → summarize

The core idea

This project is really an evaluate-and-retry loop, not a single pipeline. That's what makes it "agentic" rather than just a script. The graph needs to be able to say "these results are weak, let me search again with different terms" instead of always running once and stopping.

Tech stack

Keep it lean for v1:

LangGraph.js (@langchain/langgraph) + @langchain/core — orchestration
An LLM — @langchain/anthropic or @langchain/openai for the reasoning/ranking steps
Search tool — pick one to start:
Tavily API (@langchain/tavily / raw fetch) — easiest, built for agents, has a decent free tier, and returns clean structured results instead of raw HTML. I'd start here.
Alternative: SerpAPI or a raw job-board API (e.g. Adzuna has a free job search API, RemoteOK/Arbeitnow have free public APIs) — nice because you skip scraping entirely for v1.
Zod — for structured output validation (job postings, relevance scores) since LLMs are unreliable at raw JSON
Node.js + TypeScript, plain CLI or a small Express/Next API route to expose it
Optional later: a vector store (e.g. in-memory or SQLite+vector) if you want semantic relevance ranking instead of LLM-per-item scoring

Don't reach for a database, queue, or frontend yet — get the graph logic right first with console output.

USP IS REMOVING REDUNDENT DATAS



State schema

This is the most important design decision — get this right and the graph basically writes itself.

ts
import { Annotation } from "@langchain/langgraph";

const JobSearchState = Annotation.Root({
  role: Annotation<string>,
  location: Annotation<string>,
  profile: Annotation<string>, // resume text or skills summary

  searchQueries: Annotation<string[]>({
    reducer: (curr, upd) => [...curr, ...upd],
    default: () => [],
  }),

  rawResults: Annotation<JobPosting[]>({
    reducer: (curr, upd) => [...curr, ...upd],
    default: () => [],
  }),

  dedupedResults: Annotation<JobPosting[]>({ default: () => [] }),
  rankedResults: Annotation<RankedJob[]>({ default: () => [] }),

  retryCount: Annotation<number>({ default: () => 0 }),
  qualityOk: Annotation<boolean>({ default: () => false }),
});

Define JobPosting (title, company, location, url, source, description) and RankedJob (extends it with relevanceScore, reasoning) as Zod schemas so the LLM's structured output nodes can validate against them.

Graph architecture
        START
          │
   generate_queries        (LLM: role+location → 3-5 search query variants)
          │
      search_jobs   ◄────────────┐   (fan-out: run each query, tool calls)
          │                      │
     dedupe_results              │
          │                      │
      rank_by_profile            │   (LLM scores each posting vs profile)
          │                      │
     evaluate_quality ───weak────┘   (conditional edge: refine queries, retry)
          │
         good
          │
     format_output
          │
         END

Node-by-node:

generate_queries — LLM takes role + location, produces several query variants (different phrasings, site-specific queries like site:linkedin.com/jobs, synonyms for the role). This is what makes search effective instead of just running one query.
search_jobs — runs each query through your search tool. Use Promise.all to parallelize. Append results to rawResults.
dedupe_results — dedupe by normalized URL or by (title+company) fuzzy match. Pure code, no LLM needed.
rank_by_profile — LLM (or embedding similarity) scores each posting against the user's profile, returns relevanceScore + short reasoning. Structured output with Zod here is worth the setup time.
evaluate_quality — a conditional edge, not really a "node" in the visual sense: checks dedupedResults.length and how many results scored above some threshold. If too few good results and retryCount < 3, route back to generate_queries with instructions to refine (broader location, alternate titles, drop a filter). Otherwise proceed.
format_output — sorts by relevance, formats final answer.

The conditional edge is the crux of the "agentic loop" — that's the piece that separates this from a simple chain, so spend the most design time there.

Step-by-step build plan
Day 1 — Hardcode a role/location, call Tavily directly (no LangGraph yet), print raw results. Get the search tool working in isolation.
Day 2 — Add the LLM query-generation step. Compare hardcoded single-query results vs multi-query results — you should see obviously better coverage.
Day 3 — Wrap it in a minimal LangGraph: generate_queries → search_jobs → format_output, no ranking/retry yet. Get comfortable with StateGraph, addNode, compile(), invoke().
Day 4 — Add dedupe + LLM ranking node with Zod structured output.
Day 5 — Add the conditional edge for retry-on-weak-results. This is the trickiest part — test it by deliberately giving an obscure role/location to force a retry.
Day 6+ — Polish: add retryCount cap, streaming output, maybe a simple CLI or web UI, add a checkpointer (MemorySaver) so you can inspect state at each step while debugging.
One tip

Log the full state after every node while building — LangGraph's biggest debugging trap is silently losing data because a reducer didn't merge the way you expected. console.log(JSON.stringify(state, null, 2)) in each node during dev saves a lot of confusion later.

Want me to write the actual starter code — package.json, the state schema, and the first three nodes wired together?