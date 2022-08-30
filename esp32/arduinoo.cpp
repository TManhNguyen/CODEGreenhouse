#include "arduinoo.h"
#include "tds.h"
#include "ph.h"
#include "solar.h"

#define ARDUINO_READ_INTERVAL 1000


String parseData(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-2;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}

void myMFArduinoManager(unsigned long now) {
  static unsigned long prev = 0;

  // Proceed only if interval has passed
  if (now-prev < ARDUINO_READ_INTERVAL)
    return;
  prev = now;

  while(Serial2.available()){
    String theData = Serial2.readStringUntil('\n');
    String dataSensor = parseData(theData, '|', 0);
//    Serial.print(theData);
    if (dataSensor.equals("tds")) {
//      Serial.println(theData);
      setTds(parseData(theData, '|', 1).toInt());
    } else if (dataSensor.equals("ph")) {
//      Serial.println(theData);
      setPh(parseData(theData, '|', 1).toFloat());
    } else if (dataSensor.equals("solar")) {
      setSolar(parseData(theData, '|', 1).toInt());
    }
  }  
}

void initMyMFArduino() {
    Serial2.begin(115200,SERIAL_8N1, 16, 17);
}

void readArduino() {
}
