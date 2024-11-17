#pragma once

AsyncMqttClient mqttClient;

void ConnectToMqtt()
{
	Serial.println("Contectando a MQTT...");
  mqttClient.setClientId(MQTT_CLIENT);
  mqttClient.setCredentials(MQTT_USER, MQTT_PASSWORD);
	mqttClient.connect();
  
}

String GetPayloadContent(char* data, size_t len)
{
	String content = "";
	for(size_t i = 0; i < len; i++)
	{
		content.concat(data[i]);
	}
	return content;
}

void SuscribeMqtt()
{
	uint16_t packetIdSub = mqttClient.subscribe(MQTT_TOPIC, 0);
	Serial.print("Suscribiendo a QoS 2, packetId: ");
	Serial.println(packetIdSub);
}

void PublishMqtt()
{
	char* payload = getTemperatureHumidity();
	mqttClient.publish(MQTT_TOPIC, 0, true, payload);
  
  if(MQTT_PUB_ATTR){
    char* payloadAttr = getAttributes();
    mqttClient.publish(MQTT_TOPIC_ATTR, 0, true, payloadAttr);
  }

}

/*
void OnMqttReceived(char* topic, char* payload, AsyncMqttClientMessageProperties properties, size_t len, size_t index, size_t total)
{
	Serial.print("Received on ");
	Serial.print(topic);
	Serial.print(": ");

	String content = GetPayloadContent(payload, len);

	StaticJsonDocument<200> doc;
	DeserializationError error = deserializeJson(doc, content);
	if(error) return;

	unsigned long data = doc["data"];
	Serial.print("Millis:");
	Serial.println(data);
}
*/