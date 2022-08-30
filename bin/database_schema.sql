CREATE TABLE "SensorsData" (
  "id" SERIAL PRIMARY KEY,
  "ph" int,
  "tds" int,
  "light" float,
  "water_level" int,
  "humidity" int,
  "temperature" float,
  "created_at" timestamp WITH TIME ZONE DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE "Commands" (
  "id" SERIAL PRIMARY KEY,
  "name" varchar,
  "value" varchar,
  "created_at" timestamp WITH TIME ZONE DEFAULT CURRENT_TIMESTAMP
);
