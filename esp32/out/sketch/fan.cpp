#line 1 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\fan.cpp"
#include "fan.h"

#define PIN_FAN_CONTROL 4

void initFanControl() {
  pinMode(PIN_FAN_CONTROL, OUTPUT);
}

void fanControlManager() {
}

void setFan(bool status) {
  if (status == true) {
    digitalWrite(PIN_FAN_CONTROL, HIGH);
    Serial.println("Fan is ON");
  } else {
    digitalWrite(PIN_FAN_CONTROL, LOW);
    Serial.println("Fan is OFF");
  }
}
