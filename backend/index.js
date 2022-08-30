'use strict';

const express = require('express');
const WebSocket = require('ws');
const { database } = require('./database');

const PORT = process.env.PORT || 5000;
const INDEX = '/index.html';
const UNKNOWN_DEVICE_NAME = "unset";

const server = express()
    .use((req, res) => res.sendFile(INDEX, { root: __dirname }))
    .listen(PORT, () => console.log(`Listening on ${PORT}`));

const wss = new WebSocket.Server({ server });
const clients = new Map();
var lastSensorData = null;

wss.on('connection', (ws) => {
    console.log("New connection established...");
    const id = uuidv4();
    const device = UNKNOWN_DEVICE_NAME;
    const metadata = { id, device };

    clients.set(ws, metadata);

    ws.on("message", (messageAsString) => {
      try {
        const message = JSON.parse(messageAsString);
        const metadata = clients.get(ws);
  
        console.log(message);
        switch (metadata.device) {
          case UNKNOWN_DEVICE_NAME:
              if (message.command === "setDevice") {
                  metadata.device = message.device;
                  clients.set(ws, metadata);
                  console.log("Device name changed.")
              }
              break;
          case "arduino":
              if (message.command === "updateSensorData") {
                if (lastSensorData === null || 
                    JSON.stringify(lastSensorData) !== JSON.stringify(message)) {
                  saveSensorData(message);
                  lastSensorData = message;
                }
              }
              [...clients.keys()].forEach((client) => {
                  const clientMetaData = clients.get(client);
                  if (clientMetaData.device === "web") {
                      client.send(JSON.stringify(message));
                  }
              });
              break;
          case "web":
              [...clients.keys()].forEach((client) => {
                  const clientMetaData = clients.get(client);
                  if (clientMetaData.device === "arduino") {
                      saveCommand(message)
                      client.send(JSON.stringify(message));
                  }
              });
              break;
        }
      } catch (e) {
        console.log(e);
      }
    });

    ws.on("close", () => {
      console.log(id + " disconnected")
      clients.delete(ws);
    });
});

function uuidv4() {
  return 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {
    var r = Math.random() * 16 | 0, v = c == 'x' ? r : (r & 0x3 | 0x8);
    return v.toString(16);
  });
}

const saveCommand = (message) => {
  database
    .query(`INSERT INTO "Commands"(name, value)
            VALUES ('${message.command}', '${message.value}');`)
    .then(res => {
      console.log("command saved.")
    })
    .catch(err => {
      console.log(err.stack)
    })
}

const saveSensorData = (sensorData) => {
  database
    .query(`INSERT INTO "SensorsData"(ph, tds, light, water_level, humidity, temperature)
            VALUES (${sensorData.ph}, ${sensorData.tds}, ${sensorData.light},
                    ${sensorData.waterLevel}, ${sensorData.humidity}, ${sensorData.temperature});`)
    .then(res => {
      console.log("sensor data saved.")
    })
    .catch(err => {
      console.log(err.stack)
    })            

}

console.log("Websocket server started...");