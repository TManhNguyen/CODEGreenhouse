#line 1 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\arduinoo.h"
#ifndef MY_ARDUINOO_H
#define MY_ARDUINOO_H
#define BOOT_H
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

void myMFArduinoManager(unsigned long now);

void initMyMFArduino();

void readArduino();

#endif
