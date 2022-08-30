#line 1 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\bubbler.cpp"
#include "bubbler.h"

#define PIN_BUBBLER_CONTROL 17  

void initBubblerControl() {
  pinMode(PIN_BUBBLER_CONTROL, OUTPUT);
}

void bubblerControlManager() {
}

void setBubbler(bool status) {
  if (status == true) {
    digitalWrite(PIN_BUBBLER_CONTROL, HIGH);
    Serial.println("Bubbler is ON");
  } else {
    digitalWrite(PIN_BUBBLER_CONTROL, LOW);
    Serial.println("Bubbler is OFF");
  }
}
