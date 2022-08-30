#line 1 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\pump.cpp"
#include "pump.h"
#include "water-level.h"

#define PIN_PUMP_CONTROL 18

void initPumpControl() {
  pinMode(PIN_PUMP_CONTROL, OUTPUT);
}

void pumpControlManager() {
  if (readWaterLevelSensor() >= 90) {
    Serial.println("Auto cut off pump due to water lvl maxed");
    setPump(false);
  }
}

void setPump(bool status) {
  if (status == true) {
    digitalWrite(PIN_PUMP_CONTROL, HIGH);
    Serial.println("Pump is ON");
  } else {
    digitalWrite(PIN_PUMP_CONTROL, LOW);
    Serial.println("Pump is OFF");
  }
}
