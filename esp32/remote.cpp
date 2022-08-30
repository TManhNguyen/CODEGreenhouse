#include <WiFi.h>
#include <ArduinoWebsockets.h>
#include <ArduinoJson.h>
#include "remote.h"
#include "led.h"
#include "pump.h"
#include "fan.h"
#include "bubbler.h"

#define WIFI_SSID   "Hotspotify" 
#define WIFI_PASS   "huhuhuhu" 
#define ONBOARD_LED 2

#define WEBSOCKET_IP    "code-greenhouse-backend.herokuapp.com" 
#define WEBSOCKET_PORT  80
#define WEBSOCKET_ROUTE "/"

const char ssl_ca_cert[] PROGMEM = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIF1DCCBLygAwIBAgIQDZ5vJeCPQ3ZROu/v7BtC7zANBgkqhkiG9w0BAQsFADBG\n" \
"MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRUwEwYDVQQLEwxTZXJ2ZXIg\n" \
"Q0EgMUIxDzANBgNVBAMTBkFtYXpvbjAeFw0yMTA2MDEwMDAwMDBaFw0yMjA2MzAy\n" \
"MzU5NTlaMBoxGDAWBgNVBAMMDyouaGVyb2t1YXBwLmNvbTCCASIwDQYJKoZIhvcN\n" \
"AQEBBQADggEPADCCAQoCggEBALNy6VL9MDUWfxgLCRe5ZJwbEaroWasBNlaZurpV\n" \
"vuZjBl1WZvfTjlhuRM3a+TE2+8j0yY7Nbi9dFKCxG7V4t4BqAYKd0LDqwE1v2W6i\n" \
"72+8aRifsb7eh8udYkd4nusi1Phe69v0X5yRRY8UY0GhT+GQa3bQf39iyTf72LvI\n" \
"dzW5bmSzx2GGIf5X4tmo0G0c83qmsLHv/WQiiT7+rqsVd3ntrT4rO3A34sjbcYDl\n" \
"Zx7sVtVR9VG+kRq9k9WZiT/KQedrd5EkoFPgLzw82Ohykvgpn2vCLBz2f2ztWIB8\n" \
"8lg1PcuKkBJ4F07uotxFCXgVnWLduTDjWvNYziYxjORoiiUCAwEAAaOCAugwggLk\n" \
"MB8GA1UdIwQYMBaAFFmkZgZSoHuVkjyjlAcnlnRb+T3QMB0GA1UdDgQWBBQ45Vtp\n" \
"NoLdKHKQKgpWN1cLNuoTfDAaBgNVHREEEzARgg8qLmhlcm9rdWFwcC5jb20wDgYD\n" \
"VR0PAQH/BAQDAgWgMB0GA1UdJQQWMBQGCCsGAQUFBwMBBggrBgEFBQcDAjA7BgNV\n" \
"HR8ENDAyMDCgLqAshipodHRwOi8vY3JsLnNjYTFiLmFtYXpvbnRydXN0LmNvbS9z\n" \
"Y2ExYi5jcmwwEwYDVR0gBAwwCjAIBgZngQwBAgEwdQYIKwYBBQUHAQEEaTBnMC0G\n" \
"CCsGAQUFBzABhiFodHRwOi8vb2NzcC5zY2ExYi5hbWF6b250cnVzdC5jb20wNgYI\n" \
"KwYBBQUHMAKGKmh0dHA6Ly9jcnQuc2NhMWIuYW1hem9udHJ1c3QuY29tL3NjYTFi\n" \
"LmNydDAMBgNVHRMBAf8EAjAAMIIBfgYKKwYBBAHWeQIEAgSCAW4EggFqAWgAdwAp\n" \
"eb7wnjk5IfBWc59jpXflvld9nGAK+PlNXSZcJV3HhAAAAXnIpXWPAAAEAwBIMEYC\n" \
"IQCjQse4vq/dGyzNkVRstnLtnL9RxTsuWggbmQAGJKvFDQIhAO9QwGltSeOfKVfz\n" \
"wTym6a75/5iVDeD8OEXGDNVDFdkhAHYAIkVFB1lVJFaWP6Ev8fdthuAjJmOtwEt/\n" \
"XcaDXG7iDwIAAAF5yKV1cAAABAMARzBFAiEAySD/iqB2dtB4Eu/UkeJbFV27oJzG\n" \
"UDWZq1bgO1xxNfICIEA2fEyCx59Pw55/7lrUK940oI6sIhYXg8guM6cTR7UdAHUA\n" \
"UaOw9f0BeZxWbbg3eI8MpHrMGyfL956IQpoN/tSLBeUAAAF5yKV1sQAABAMARjBE\n" \
"AiBdqlEUQE4qYpX5AIcDLjnsaJQ5ojXosipLvTSYz7wOKwIgJb79hIEM3iLqqnFi\n" \
"FLMuFqOU1Bfa1HpkVyZ/d2AqjGQwDQYJKoZIhvcNAQELBQADggEBABagkSdzBJDm\n" \
"ebm5a3sPkZ6wGyJtMdDTmDV/kon5l9m+p3yge0GPygGxvZh3kXSOn82w5edQEF/J\n" \
"ikg86cPkwjLv++djIuVXhVK0EXC3qA/44CqBOGqfWTYQN/Wf0Sdn/4oiRBl6YUo4\n" \
"2Li6DIBbrtlkFbHbOMQmbmE4ftFnvUikwWE2KkjUddVfEE+FZXsMXl5z741KoqJ0\n" \
"LSDwVoG6bh6P12Dn3Lhpp7XOVlHx/0cnO+1RchpwgbthM36vWLyM2tQyo3t78/7g\n" \
"mTHtDMNYWMPhxra6rrz3A7wtCPdJelKRbuGz6mSMUTad492F4YuAo6/DR7vX2QMb\n" \
"vHTsSvmjOhU=\n" \
"-----END CERTIFICATE-----\n" \
"";



using namespace websockets;

WebsocketsClient client;

void onMessageCallback(WebsocketsMessage message) {
  Serial.println(message.data());

  const int capacity = JSON_OBJECT_SIZE(6);
  StaticJsonDocument<capacity> doc;

  DeserializationError err = deserializeJson(doc, message.data());
  if (err) {
    Serial.print(F("deserializeJson() failed with code "));
    Serial.println(err.f_str());
  } else {
    const char* command = doc["command"];
    const char* device = doc["device"];

    if (strcmp(command, "setPump") == 0) {
      if (doc["value"].as<int>() == 1) {
        // turn on pump
        setPump(true);
      } else {
        // turn off pump
        setPump(false);
      }
    } else if (strcmp(command, "setLight") == 0) {
      if (doc["value"].as<int>() == 1) {
        // turn on light
        setLight(true);
      } else {
        // turn off light
        setLight(false);
      } 
    } else if (strcmp(command, "setBubbler") == 0) {
      if (doc["value"].as<int>() == 1) {
        // turn on bubbler
        setBubbler(true);
      } else {
        // turn off bubbler
        setBubbler(false);
      } 
    } else if (strcmp(command, "setFan") == 0) {
      if (doc["value"].as<int>() == 1) {
        // turn on fan
        setFan(true);
      } else {
        // turn off fan
        setFan(false);
      }
    } else if (strcmp(command, "getSettings") == 0) {
      // send current settings to Web
    }
  }

  
}

void onEventsCallback(WebsocketsEvent event, String data) {
  if (event == WebsocketsEvent::ConnectionOpened) {
    Serial.println("Connnection Opened");
  } else if (event == WebsocketsEvent::ConnectionClosed) {
    Serial.println("Connnection Closed");
  } else if (event == WebsocketsEvent::GotPing) {
    Serial.println("Got a Ping!");
  } else if (event == WebsocketsEvent::GotPong) {
    Serial.println("Got a Pong!");
  }
}


void connectWifi() {
  bool connectBlink = false;
  Serial.printf("Connecting to %s", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    connectBlink = !connectBlink;
    digitalWrite(ONBOARD_LED, connectBlink);
    delay(500);
    Serial.print(".");
  }
  digitalWrite(ONBOARD_LED, LOW);
  Serial.println(" WIFI CONNECTED!");
  Serial.println(WiFi.localIP());

}

void connectWebsocket() {
  Serial.printf("Connecting to Websocket\n");
  digitalWrite(ONBOARD_LED, HIGH);

  // Setup Callbacks
  client.onMessage(onMessageCallback);
  client.onEvent(onEventsCallback);

  // Before connecting, set the ssl fingerprint of the server
//  client.setCACert(ssl_ca_cert);
    
  // Connect to server
  bool connected = client.connect(
                     WEBSOCKET_IP,
                     WEBSOCKET_PORT,
                     WEBSOCKET_ROUTE);
  if (connected) {
    Serial.println("Connected!");
    digitalWrite(ONBOARD_LED, LOW);

    char output[128];
    const int capacity = JSON_OBJECT_SIZE(3);
    StaticJsonDocument<capacity> doc; 
    doc["command"] = "setDevice";
    doc["device"] = "arduino";

    serializeJson(doc, output);

    client.send(output);
  } else {
    Serial.println("Not Connected!");
    digitalWrite(ONBOARD_LED, HIGH);
  }

  // Send a ping
  client.ping();
}


void remoteManager() {
  if (client.available()) {
    client.poll();
  } else {
    connectWebsocket();
  }
}

void initRemote() {
  pinMode(ONBOARD_LED, OUTPUT);
  connectWifi();
  connectWebsocket();
}

void sendSensorData(unsigned long now, float temperature, float humidity, int waterLevel, float light, float tds, int ph, int solar) {
    static unsigned long prev = 0;

    if (now-prev < 2000)
      return;
    prev = now;

    if (temperature == NULL || 
        humidity == NULL) {
      return;
    }

    char output[256];
    const int capacity = JSON_OBJECT_SIZE(11);
    StaticJsonDocument<capacity> doc; 
    doc["command"] = "updateSensorData";
    doc["device"] = "arduino";
    doc["temperature"] = temperature;
    doc["humidity"] = humidity;
    doc["waterLevel"] = waterLevel;
    doc["light"] = light;
    doc["tds"] = tds;
    doc["ph"] = ph;
    doc["solar"] = solar;
    
    serializeJson(doc, output);

    client.send(output);   
}

void sendDummySensorData(unsigned long now) {
    static unsigned long prev = 0;

    if (now-prev < 2000)
      return;
    prev = now;
    
    char output[128];
    const int capacity = JSON_OBJECT_SIZE(5);
    StaticJsonDocument<capacity> doc; 
    doc["command"] = "updateSensorData";
    doc["device"] = "arduino";
    doc["temperature"] = random(30, 50);
    doc["humidity"] = random(20, 80);
    doc["waterLevel"] = random(0, 100);

    serializeJson(doc, output);

    client.send(output); 
}
