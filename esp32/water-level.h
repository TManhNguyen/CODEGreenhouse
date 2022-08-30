#ifndef WATER_LEVEL_SENSOR_H
#define WATER_LEVEL_SENSOR_H
#define BOOT_H
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

void waterLevelSensorManager(unsigned long now);

void initWaterLevelSensor();

int readWaterLevelSensor();

#endif