#line 1 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\ph.cpp"
#include "ph.h"

#define PIN_PH 25
#define PH_SAMPLING_INTERVAL 1000
#define PH_READ_INTERVAL 10000

int ph;

void phSensorManager(unsigned long now) {
  static unsigned long prev = 0;

   if(now-prev > PH_SAMPLING_INTERVAL)
   {

   }   

  // Proceed only if interval has passed
  if (now-prev < PH_READ_INTERVAL)
    return;


  
  prev = now;
  
}

void initPhSensor() {
//  pinMode(PIN_PH,INPUT);
}


void setPh(int value) {
  ph = value;
//  Serial.print("setPh = ");
//  Serial.println(ph);  
}

int readPhSensor() {
//    Serial.print("readPh = ");
//  Serial.println(ph);
  return ph;
}
