#ifndef DHT_SENSOR_H
#define DHT_SENSOR_H
#define BOOT_H
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

void dhtSensorManager(unsigned long now);

void initDhtSensor();

float readHumiditySensor();

float readTemperatureSensor();

#endif
