#ifndef SOLAR_SENSOR_H
#define SOLAR_SENSOR_H
#define BOOT_H
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

void solarSensorManager(unsigned long now);

void initSolarSensor();

void setSolar(int value);

int readSolarSensor();

#endif
