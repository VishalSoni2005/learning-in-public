import "dotenv/config";
import readline from "readline/promises";
import { stdin as input, stdout as output } from "process";
import { app } from "./graph/graph";
import { DEFAULT_SEARCH_QUERY } from "./prompts";

// Clean user query for the Web Search Agent
const USER_QUERY = process.env.USER_QUERY || DEFAULT_SEARCH_QUERY;

// Configurable thread ID for LangGraph checkpointer state tracking
const config = { configurable: { thread_id: "hitl-agent-session-1" } };

// Console UI Formatting Helpers
function printHeader(title: string) {
  console.log("\n" + "═".repeat(80));
  console.log(` 🤖 WEB SEARCH AGENT  │  ${title}`);
  console.log("═".repeat(80));
}

function printSection(title: string, content: string | number) {
  console.log(`\n┌── ${title} ${"─".repeat(Math.max(0, 74 - title.length))}`);
  const lines = String(content).split("\n");
  for (const line of lines) {
    console.log(`│ ${line}`);
  }
  console.log(`└${"─".repeat(78)}`);
}

function printStepBanner(stepNum: number, stepName: string, description: string) {
  console.log("\n" + "─".repeat(80));
  console.log(`📍 STEP ${stepNum}/4: [ ${stepName.toUpperCase()} NODE COMPLETED ]`);
  console.log(`ℹ️  ${description}`);
  console.log("─".repeat(80));
}

async function main() {
  const rl = readline.createInterface({ input, output });

  try {
    printHeader("HUMAN-IN-THE-LOOP AGENT EXECUTION");
    console.log(`🔍 Initial Search Query: "${USER_QUERY}"`);

    // Initial graph invocation - will run up to the first interruptAfter ("search")
    let state = await app.invoke({ query: USER_QUERY }, config);

    // Node review step sequence
    const steps = [
      {
        node: "search",
        stepNum: 1,
        title: "Web Search Results",
        desc: "Raw search snippets fetched from Tavily",
        next: "filter",
        getContent: (vals: any) =>
          `Total Results: ${vals.searchResults?.length || 0}\n\n` +
          (vals.searchResults || [])
            .map((res: string, idx: number) => `[Source ${idx + 1}]\n${res.trim()}`)
            .join("\n\n----------------------------------------\n\n"),
      },
      {
        node: "filter",
        stepNum: 2,
        title: "Filtered Results",
        desc: "Noise removed & verified openings retained",
        next: "analyse",
        getContent: (vals: any) => vals.filteredResults || "No filtered results available.",
      },
      {
        node: "analyse",
        stepNum: 3,
        title: "Analytical Report",
        desc: "Comparative analysis, requirements & missing details",
        next: "summarize",
        getContent: (vals: any) => vals.analysis || "No analysis available.",
      },
    ];

    // Loop through step interruptions
    for (const step of steps) {
      const graphState = await app.getState(config);
      const values = graphState.values;

      printStepBanner(step.stepNum, step.node, step.desc);
      printSection(step.title, step.getContent(values));

      // Prompt human in the loop for review / feedback
      console.log(`\n💬 [HUMAN-IN-THE-LOOP REVIEW]`);
      console.log(`👉 Press [ENTER] to approve & continue to '${step.next}' node.`);
      console.log(`✍️  Or type custom feedback/corrections to guide the next node:`);
      
      const feedback = await rl.question("\n> ");

      if (feedback && feedback.trim().length > 0) {
        console.log(`\n✅ Recorded Human Feedback: "${feedback.trim()}"`);
        // Update state with human feedback
        await app.updateState(config, { humanFeedback: feedback.trim() });
      } else {
        console.log(`\n👍 Step approved. Continuing execution flow...`);
      }

      // Resume graph execution to next step
      await app.invoke(null, config);
    }

    // Final state retrieval after summarize completes
    const finalState = await app.getState(config);
    const finalValues = finalState.values;

    printHeader("FINAL AGENT REPORT (COMPLETE)");
    printSection("SUMMARY REPORT", finalValues.summary || "No final summary generated.");
    console.log("\n✨ Execution flow completed successfully.\n");
  } catch (error) {
    console.error("\n❌ Error during Human-in-the-Loop execution:", error);
  } finally {
    rl.close();
  }
}

main();
