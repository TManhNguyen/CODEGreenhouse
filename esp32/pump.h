#ifndef PUMP_CONTROL_H
#define PUMP_CONTROL_H
#define BOOT_H
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

void pumpControlManager();

void initPumpControl();

void setPump(bool status);

#endif

