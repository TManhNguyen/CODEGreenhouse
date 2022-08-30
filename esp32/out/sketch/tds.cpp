#line 1 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\tds.cpp"
#include "tds.h"

#define PIN_TDS 34
#define TDS_SAMPLING_INTERVAL 40U
#define TDS_READ_INTERVAL 800U

#define VREF 5.0      // analog reference voltage(Volt) of the ADC
#define SCOUNT  30           // sum of sample point
int analogBuffer[SCOUNT];    // store the analog value in the array, read from ADC
int analogBufferTemp[SCOUNT];
int analogBufferIndex = 0,copyIndex = 0;
float averageVoltage = 0,temperature = 25;
float tdsValue;

int getMedianNum(int bArray[], int iFilterLen) 
{
      int bTab[iFilterLen];
      for (byte i = 0; i<iFilterLen; i++)
      bTab[i] = bArray[i];
      int i, j, bTemp;
      for (j = 0; j < iFilterLen - 1; j++) 
      {
      for (i = 0; i < iFilterLen - j - 1; i++) 
          {
        if (bTab[i] > bTab[i + 1]) 
            {
        bTemp = bTab[i];
            bTab[i] = bTab[i + 1];
        bTab[i + 1] = bTemp;
         }
      }
      }
      if ((iFilterLen & 1) > 0)
    bTemp = bTab[(iFilterLen - 1) / 2];
      else
    bTemp = (bTab[iFilterLen / 2] + bTab[iFilterLen / 2 - 1]) / 2;
      return bTemp;
}

void tdsSensorManager(unsigned long now) {
  static unsigned long prev = 0;
  static unsigned long samplingPrev = 0;

   if(now-samplingPrev > TDS_SAMPLING_INTERVAL)
   {
     analogBuffer[analogBufferIndex] = analogRead(PIN_TDS);    //read the analog value and store into the buffer
     analogBufferIndex++;
     if(analogBufferIndex == SCOUNT) 
         analogBufferIndex = 0;
     samplingPrev = now;
   }   

  // Proceed only if interval has passed
  if (now-prev < TDS_READ_INTERVAL)
    return;

  for(copyIndex=0;copyIndex<SCOUNT;copyIndex++)
    analogBufferTemp[copyIndex]= analogBuffer[copyIndex];
  averageVoltage = getMedianNum(analogBufferTemp,SCOUNT) * (float)VREF / 1024.0; // read the analog value more stable by the median filtering algorithm, and convert to voltage value
  float compensationCoefficient=1.0+0.02*(temperature-25.0);    //temperature compensation formula: fFinalResult(25^C) = fFinalResult(current)/(1.0+0.02*(fTP-25.0));
  float compensationVolatge=averageVoltage/compensationCoefficient;  //temperature compensation
//  tdsValue=(133.42*compensationVolatge*compensationVolatge*compensationVolatge - 255.86*compensationVolatge*compensationVolatge + 857.39*compensationVolatge)*0.5; //convert voltage value to tds value
//  Serial.print("voltage:");
//  Serial.print(averageVoltage,2);
//  Serial.print("V   ");
//  Serial.print("TDS Value:");
//  Serial.print(tdsValue,0);
//  Serial.println("ppm");
//  Serial.printf("[%d] Current tds value: %f\n", prev, tdsValue);
  
  prev = now;
  
}

void initTdsSensor() {
//  pinMode(PIN_TDS,INPUT);
}

void setTds(float value) {
  tdsValue = value;
//  Serial.print("setTds = ");
//  Serial.println(tdsValue);
}

float readTdsSensor() {
//    Serial.print("readTds = ");
//  Serial.println(tdsValue);
  return tdsValue;
}
