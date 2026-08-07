import { tool } from "langchain";
import { getWeatherData } from "../utils/weather.js";
import { z } from "zod";

export const weatherTool = tool(
  async ({ city }: { city: string }) => {
    try {
      const weather = await getWeatherData(city);

      return JSON.stringify(weather, null, 2);
    } catch (err: any) {
      return `Couldn't fetch weather for ${city}. ${err.message}`;
    }
  },
  {
    name: "weather",
    description: "Get current weather information for a city.",
    schema: z.object({
      city: z.string().describe("City name"),
    }),
  },
);
