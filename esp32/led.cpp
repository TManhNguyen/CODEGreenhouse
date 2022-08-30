#include "led.h"

#define PIN_LED_CONTROL 5

void initLedControl() {
  pinMode(PIN_LED_CONTROL, OUTPUT);
}

void setLight(bool status) {
  if (status == true) {
    digitalWrite(PIN_LED_CONTROL, LOW);
    Serial.println("LED is ON");
  } else {
    digitalWrite(PIN_LED_CONTROL, HIGH);
    Serial.println("LED is OFF");
  }
}

void ledControlManager() {
}
