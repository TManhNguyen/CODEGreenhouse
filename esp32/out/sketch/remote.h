#line 1 "c:\\Users\\thanhlongb\\Documents\\Arduino\\code-iot-firmware\\remote.h"
#ifndef REMOTE_H
#define REMOTE_H

void initRemote();

void remoteManager();

void sendSensorData(unsigned long now, int temperature, int humidity, float waterLevel, float light, float tds, int ph);

void sendDummySensorData(unsigned long now);

#endif
