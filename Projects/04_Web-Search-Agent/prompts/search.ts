/**
 * SEARCH_PROMPT
 * System prompt and search query definitions for web search operations.
 */

export const SEARCH_SYSTEM_PROMPT = `You are a Search Query Optimization Expert.

Your role is to formulate targeted, keyword-dense search queries designed to retrieve accurate, recent, and highly relevant search results from web search engines.

### Query Formulation Rules:
- Focus on high-intent keywords rather than conversational instructions.
- Include specific domain terms, locations, roles, and constraints where appropriate.
- Prioritize trusted portals and official source domains.`;

/**
 * Default multi-role search query tailored for freshers & interns across:
 * React Developer, Backend Developer, AI Engineer, GenAI Developer, Software Engineer.
 */
export const DEFAULT_SEARCH_QUERY =
  "React Developer OR Backend Developer OR AI Engineer OR GenAI Developer OR Software Engineer internship fresher openings Pune";

/**
 * Role-specific preset queries for targeted searches.
 */
export const PRESET_SEARCH_QUERIES = {
  ALL_ROLES:
    "React Developer OR Backend Developer OR AI Engineer OR GenAI Developer OR Software Engineer internship fresher Pune",
  REACT_FRONTEND: "React Developer OR Frontend Engineer internship fresher Pune",
  BACKEND_NODE: "Backend Developer OR Node.js Engineer OR Python Engineer internship fresher Pune",
  AI_GENAI: "AI Engineer OR GenAI Developer OR LLM Engineer internship fresher Pune",
  SOFTWARE_ENGG: "Software Engineer OR Full Stack Developer entry level fresher internship Pune",
};

/**
 * Helper to build custom search queries dynamically.
 */
export function buildJobSearchQuery(options: {
  roles?: string[];
  location?: string;
  type?: "internship" | "fresher" | "both";
}): string {
  const rolesList =
    options.roles && options.roles.length > 0
      ? options.roles.join(" OR ")
      : "Software Engineer OR React Developer OR Backend Developer OR AI Engineer";
  const location = options.location || "Pune";
  const type = options.type === "internship" ? "internship" : options.type === "fresher" ? "fresher" : "internship fresher";

  return `${rolesList} ${type} ${location}`;
}
