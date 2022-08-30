#ifndef REMOTE_H
#define REMOTE_H

void initRemote();

void remoteManager();

void sendSensorData(unsigned long now, float temperature, float humidity, int waterLevel, float light, float tds, int ph, int solar);

void sendDummySensorData(unsigned long now);

#endif
