#include "water-level.h"

#define PIN_WATER_SENSOR 35
#define SENSOR_MIN 900
#define SENSOR_MAX 1600
#define WATER_LEVEL_READ_INTERVAL  10000

void waterLevelSensorManager(unsigned long now) {
  static unsigned long prev = 0;

  // Proceed only if interval has passed
  if (now-prev < WATER_LEVEL_READ_INTERVAL)
    return;
  prev = now;
  
  Serial.printf("[%d] Current water level value: %d\n", prev, readWaterLevelSensor());
}

void initWaterLevelSensor() {
 pinMode(PIN_WATER_SENSOR, INPUT); 
}

int readWaterLevelSensor() {
  int sensorValue = 0;
  int percentage;

  for (int i = 0; i < 5; ++i) {
    sensorValue += analogRead(PIN_WATER_SENSOR); // read the analog value from sensor
  }
  sensorValue /= 5; // read the analog value from sensor
  percentage = map(constrain(sensorValue, SENSOR_MIN, SENSOR_MAX), SENSOR_MIN, SENSOR_MAX, 0, 100); 

  return percentage;
}
