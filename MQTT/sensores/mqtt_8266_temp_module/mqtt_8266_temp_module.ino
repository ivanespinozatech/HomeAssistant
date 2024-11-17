#include <ESP8266WiFi.h>
#include <AsyncMqttClient.h>
#include <ArduinoJson.h>
#include "config.h"
#include "WIFI_Utils.hpp"
#include "DHT.h"
#include "MQTT.hpp"
#include "MQTT_Async.hpp"
void setup()
{
	Serial.begin(115200);
	delay(500);
	WiFi.onEvent(WiFiEvent);
	ConnectWiFi();
  InitMqtt();
}

void loop()
{
	PublishMqtt();
	delay(MQTT_PUB_DELAY);
}