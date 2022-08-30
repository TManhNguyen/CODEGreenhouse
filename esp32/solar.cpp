#include "solar.h"

#define SOLAR_READ_INTERVAL  10000

int solar;

void solarSensorManager(unsigned long now) {
  static unsigned long prev = 0;

  // Proceed only if interval has passed
  if (now-prev < SOLAR_READ_INTERVAL)
    return;
  prev = now;
  
  Serial.printf("[%d] Current solar value: %d\n", prev, readSolarSensor());
}

void initSolarSensor() {
//  pinMode(PIN_SOLAR_SENSOR, INPUT); 
}

void setSolar(int value) {
  solar = value;
}

int readSolarSensor() {
  return solar;
}
