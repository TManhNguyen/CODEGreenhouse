#line 1 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\bubbler.h"
#ifndef BUBBLER_CONTROL_H
#define BUBBLER_CONTROL_H
#define BOOT_H
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

void bubblerControlManager();

void initBubblerControl();

void setBubbler(bool status);

#endif
