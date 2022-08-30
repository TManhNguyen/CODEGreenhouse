#line 1 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\led.h"
#ifndef LED_CONTROL_H
#define LED_CONTROL_H
#define BOOT_H
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif
#include <FastLED.h>

void ledControlManager();

void initLedControl();

void setStripColor(uint32_t color);

void setLight(bool status);

#endif
