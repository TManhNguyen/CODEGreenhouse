#ifndef TDS_SENSOR_H
#define TDS_SENSOR_H
#define BOOT_H
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

void tdsSensorManager(unsigned long now);

void initTdsSensor();

void setTds(float value);

float readTdsSensor();

#endif
