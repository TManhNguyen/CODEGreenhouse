#line 1 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\light.cpp"
#include "light.h"

#define PIN_LIGHT_SENSOR 34
#define LIGHT_READ_INTERVAL  1000
#define RESISTANCE 10              // Resistance in the circuit of sensor (KOhms)
#define MAX_VOLTAGE  5

void initLightSensor() {
  pinMode(PIN_LIGHT_SENSOR, INPUT); 
}

void lightSensorManager(unsigned long now) {
  static unsigned long prev = 0;
  // Proceed only if interval has passed
  // Serial.printf("now = %d, prev = %d\n", now, prev);
  if (now-prev < LIGHT_READ_INTERVAL)
    return;
  prev = now;
  
  Serial.printf("[%d] Current light sensor value: %d\n", prev, readLighttSensor());
}

float readLighttSensor() {
  static float prevLuxValue;

  int lightReading = analogRead(PIN_LIGHT_SENSOR);   // Read the analogue pin
//  float voltage = lightReading*0.0048828125;      // calculate the voltage
//  int luxValue = 5000/(RESISTANCE*((5-voltage)/voltage));           // calculate the Lux
//
//  if (prevLuxValue != 0) {
//    prevLuxValue = constrain(luxValue, prevLuxValue*0.99, prevLuxValue*1.01);  
//  } else {
//    prevLuxValue = luxValue;
//  }

  if (prevLuxValue != 0) {
    prevLuxValue = constrain(lightReading, prevLuxValue*0.99, prevLuxValue*1.01);  
  } else {
    prevLuxValue = lightReading;
  }


  return prevLuxValue;
}
