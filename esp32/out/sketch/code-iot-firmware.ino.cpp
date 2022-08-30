#include <Arduino.h>
#line 1 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\code-iot-firmware.ino"
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
#include "arduinoo.h"

#line 14 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\code-iot-firmware.ino"
void setup();
#line 73 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\code-iot-firmware.ino"
void loop();
#line 84 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\code-iot-firmware.ino"
void stateManager();
#line 14 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\code-iot-firmware.ino"
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

  // Go to initial mode
  // Note: No mode, for now.
  // goToMode(INITIAL_MODE);
}


void loop() {
  // Time-independent operations
  // readButton();
  remoteManager();
//   ledControlManager();
  // pumpControlManager();
  stateManager();
}



void stateManager()
{
  // Time-dependent operations 
  // static byte prevDisplayMode = -1;
  
  unsigned long now = millis();

  sendSensorData(
    now, 
    readTemperatureSensor(), 
    readHumiditySensor(), 
    readWaterLevelSensor(),
    readLighttSensor(),
    readTdsSensor(),
    readPhSensor()
//    readLightSensor()
  );
  myMFArduinoManager(now);
//    lightSensorManager(now);
//  tdsSensorManager(now);
  // boolean modeChanged = prevDisplayMode != displayMode;
  // prevDisplayMode = displayMode;

  // Run state-dependent code
  // switch (displayMode)
  // {
  //   case MODE_WORD_CLOCK:
  //   case MODE_DIGITAL_CLOCK:
  //     clockManager(now, modeChanged);
  //     break;
  //   case MODE_TETRIS:
  //     tetrisManager(now, modeChanged);
  //     break;
  //   default:
  //     displayMode = INITIAL_MODE;
  //     break;
  // }

  // State-independent code
  // lightSensorManager(now);
//   waterLevelSensorManager(now);
}

