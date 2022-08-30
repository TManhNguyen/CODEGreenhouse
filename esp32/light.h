#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H
#define BOOT_H
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

void lightSensorManager(unsigned long now);

void initLightSensor();

float readLighttSensor();

#endif
