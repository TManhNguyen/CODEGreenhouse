#line 1 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\water-level.cpp"
  #include "water-level.h"

//#define PIN_US_TRIG 18
//#define PIN_US_ECHO 19
//#define SOUND_SPEED 0.034
#define PIN_WATER_SENSOR 35
#define SENSOR_MIN 900
#define SENSOR_MAX 1600
#define WATER_LEVEL_READ_INTERVAL  10000

void waterLevelSensorManager(unsigned long now) {
  static unsigned long prev = 0;

  // Proceed only if interval has passed
  if (now-prev < WATER_LEVEL_READ_INTERVAL)
    return;
  prev = now;
  
  Serial.printf("[%d] Current water level value: %d\n", prev, readWaterLevelSensor());
}

void initWaterLevelSensor() {
// pinMode(PIN_US_TRIG, OUTPUT); // Sets the trigPin as an Output
// pinMode(PIN_US_ECHO, INPUT); // Sets the echoPin as an Input
 pinMode(PIN_WATER_SENSOR, INPUT); 
}

int readWaterLevelSensor() {
//  long duration;
//  static float lastDistance;
//  float distance;
  int sensorValue = 0;
  int percentage;

  for (int i = 0; i < 5; ++i) {
    sensorValue += analogRead(PIN_WATER_SENSOR); // read the analog value from sensor
  }
  sensorValue /= 5; // read the analog value from sensor
  percentage = map(constrain(sensorValue, SENSOR_MIN, SENSOR_MAX), SENSOR_MIN, SENSOR_MAX, 0, 100); 

//  for (int i = 0; i < 5; ++i) {
//    digitalWrite(PIN_US_TRIG, LOW);
//    delayMicroseconds(2);
//     Sets the trigPin on HIGH state for 10 micro seconds
//    digitalWrite(PIN_US_TRIG, HIGH);
//    delayMicroseconds(10);
//    digitalWrite(PIN_US_TRIG, LOW);
  
//     Reads the echoPin, returns the souxnd wave travel time in microseconds
//    duration = pulseIn(PIN_US_ECHO, HIGH);
//    Serial.println(duration * SOUND_SPEED/2);
//    distance = constrain(duration * SOUND_SPEED/2, 6, 13);
//    distance += duration * SOUND_SPEED/2;      
//  }

//  distance = distance/5;
//  if (distance - lastDistance > 1) {
//    lastDistance += 0.5;
//  } else if (distance - lastDistance < -1) {
//    lastDistance -= 0.5;
//  } else {
//     lastDistance = distance;
//  }
//
//  
//  percentage = map(13 - lastDistance, 6, 13, 0, 100);

//  Serial.printf("%f -> %d\n", lastDistance, percentage);
  
  // Calculate the distance
  return percentage;
}
