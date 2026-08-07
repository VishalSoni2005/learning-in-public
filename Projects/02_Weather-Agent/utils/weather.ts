import axios from "axios";
import dotenv from "dotenv";

dotenv.config({
  path: "../../.env",
});

export async function getWeatherData(city: string) {
  const apiKey = process.env.WEATHER_API_KEY;
  const apiUrl = process.env.WEATHER_API_URL;

  const response = await axios.get(apiUrl!, {
    params: {
      q: city,
      appid: apiKey,
      units: "metric",
    },
  });

  const data = response.data;

  return {
    city: data.name,
    country: data.sys.country,
    temperature: data.main.temp,
    feelsLike: data.main.feels_like,
    humidity: data.main.humidity,
    pressure: data.main.pressure,
    weather: data.weather[0].main,
    description: data.weather[0].description,
    windSpeed: data.wind.speed,
    visibility: data.visibility,
  };
}
