// Import libraries
#include "remote.h"
#include "light.h"
#include "water-level.h"
#include "led.h"
#include "fan.h"
#include "pump.h"
#include "bubbler.h"
#include "dhts.h"
#include "tds.h"
#include "ph.h"
#include "solar.h"
#include "arduinoo.h"

void setup() {
  // Debug info
  Serial.begin(115200);

  Serial.println(F("CODE-IOT is booting"));
  
  // Initiate the remote control
  Serial.println(F("Init remote control"));
  initRemote();

  // Initiate the light sensor
  Serial.println(F("Init light sensor"));
  initLightSensor();

  // Initiate the water level sensor
  Serial.println(F("Init water level sensor"));
  initWaterLevelSensor();

  // Initiate the solar sensor
  Serial.println(F("Init solar sensor"));
  initSolarSensor();

  // Initiate the led control
  Serial.println(F("Init led control"));
  initLedControl();

  // Initiate the pump
  Serial.println(F("Init pump"));
  initPumpControl();

  // Initiate the fan
  Serial.println(F("Init fan"));
  initFanControl();

  // Initiate the bubbler
  Serial.println(F("Init bubbler"));
  initBubblerControl();

  // Initiate the dht
  Serial.println(F("Init dht"));
  initDhtSensor();

  // Initiate the tds
  Serial.println(F("Init tds"));
  initTdsSensor();

  // Initiate the ph
  Serial.println(F("Init ph"));
  initPhSensor();

  // Initiate the arduino
  Serial.println(F("Init arduino"));
  initMyMFArduino();


  Serial.println(F("Done. Hello!"));

}


void loop() {
  remoteManager();
  stateManager();
}



void stateManager()
{  
  unsigned long now = millis();

  sendSensorData(
    now, 
    readTemperatureSensor(), 
    readHumiditySensor(), 
    readWaterLevelSensor(),
    readLighttSensor(),
    readTdsSensor(),
    readPhSensor(),
    readSolarSensor()
  );
  myMFArduinoManager(now);
}
