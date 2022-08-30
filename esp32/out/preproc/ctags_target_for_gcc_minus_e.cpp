# 1 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\code-iot-firmware.ino"
// Import libraries
# 3 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\code-iot-firmware.ino" 2
# 4 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\code-iot-firmware.ino" 2
# 5 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\code-iot-firmware.ino" 2
# 6 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\code-iot-firmware.ino" 2
# 7 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\code-iot-firmware.ino" 2
# 8 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\code-iot-firmware.ino" 2
# 9 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\code-iot-firmware.ino" 2
# 10 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\code-iot-firmware.ino" 2
# 11 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\code-iot-firmware.ino" 2
# 12 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\code-iot-firmware.ino" 2
# 13 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\code-iot-firmware.ino" 2

void setup() {
  // Debug info
  Serial.begin(115200);

  Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("CODE-IOT is booting")))));

  // Initiate the remote control
  Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("Init remote control")))));
  initRemote();

  // Initiate the light sensor
  Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("Init light sensor")))));
  initLightSensor();

  // Initiate the water level sensor
  Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("Init water level sensor")))));
  initWaterLevelSensor();

  // Initiate the led control
  Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("Init led control")))));
  initLedControl();

  // Initiate the pump
  Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("Init pump")))));
  initPumpControl();

  // Initiate the fan
  Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("Init fan")))));
  initFanControl();

  // Initiate the bubbler
  Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("Init bubbler")))));
  initBubblerControl();

  // Initiate the dht
  Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("Init dht")))));
  initDhtSensor();

  // Initiate the tds
  Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("Init tds")))));
  initTdsSensor();

  // Initiate the ph
  Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("Init ph")))));
  initPhSensor();

  // Initiate the arduino
  Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("Init arduino")))));
  initMyMFArduino();


  Serial.println(((reinterpret_cast<const __FlashStringHelper *>(("Done. Hello!")))));

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
