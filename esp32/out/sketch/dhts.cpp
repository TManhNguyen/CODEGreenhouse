#line 1 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\dhts.cpp"
#include "dhts.h"
#include "DHT.h"

#define PIN_DHT 13
#define DHTTYPE DHT11
#define DHT_READ_INTERVAL  10000

DHT dht(PIN_DHT, DHTTYPE);

void dhtSensorManager(unsigned long now) {
  static unsigned long prev = 0;

  // Proceed only if interval has passed
  if (now-prev < DHT_READ_INTERVAL)
    return;
  prev = now;
  
//  Serial.printf("[%d] Current dht value: %f\n", prev, readDhtSensor());
}

void initDhtSensor() {
  dht.begin(); // initialize the sensor
}

float readHumiditySensor() {
  return dht.readHumidity();
}

float readTemperatureSensor() {
  return dht.readTemperature();
}
