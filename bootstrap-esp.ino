#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

void setup()
{
  Serial.begin(115200);

  WiFiManager wifiManager;
  wifiManager.setTimeout(180);

  (!wifiManager.autoConnect("ESP-auto")) {
    Serial.println("failed to connect, we should reset as see if it connects");
    delay(1000);
    ESP.reset();
  }

  ArduinoOTA.setHostname("esp-auto");
  ArduinoOTA.begin();
}

void loop() {
  ArduinoOTA.handle();
}