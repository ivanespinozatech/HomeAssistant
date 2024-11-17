#include "DHT.h"
#include <ArduinoJson.h>

DHT11 dht(2);

String payload = "";
StaticJsonDocument<300> jsonDoc;

char* getTemperatureHumidity() {
  int temperature = dht.readTemperature();
  int humidity = dht.readHumidity();

  if(temperature < 100 && humidity < 100){
    jsonDoc["temperature"] = temperature;
    jsonDoc["humidity"] = humidity;
  }
  
	serializeJson(jsonDoc, payload);
	return (char*)payload.c_str();
}
