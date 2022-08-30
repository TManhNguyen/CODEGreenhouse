#ifndef PH_SENSOR_H
#define PH_SENSOR_H
#define BOOT_H
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

void phSensorManager(unsigned long now);

void initPhSensor();

int readPhSensor();

void setPh(int value);

#endif
