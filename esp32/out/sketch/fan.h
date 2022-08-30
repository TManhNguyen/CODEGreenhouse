#line 1 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\fan.h"
#ifndef FAN_CONTROL_H
#define FAN_CONTROL_H
#define BOOT_H
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

void fanControlManager();

void initFanControl();

void setFan(bool status);

#endif
