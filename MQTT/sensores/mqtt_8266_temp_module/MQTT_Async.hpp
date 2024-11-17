#pragma once

void OnMqttConnect(bool sessionPresent)
{
	Serial.println("Conectado al broker MQTT.");
	Serial.print("Session: ");
	Serial.println(sessionPresent);
	SuscribeMqtt();
}

void OnMqttDisconnect(AsyncMqttClientDisconnectReason reason)
{
	Serial.println("Desconectado del broker MQTT.");
}

void OnMqttSubscribe(uint16_t packetId, uint8_t qos)
{
	Serial.println("Subscribe.");
	Serial.print("  packetId: ");
	Serial.println(packetId);
	Serial.print("  qos: ");
	Serial.println(qos);
}

void OnMqttUnsubscribe(uint16_t packetId)
{
	Serial.println("Unsubscribe.");
	Serial.print("  packetId: ");
	Serial.println(packetId);
}


void OnMqttPublish(uint16_t packetId)
{
	Serial.println("Publish.");
	Serial.print("  packetId: ");
	Serial.println(packetId);
}

void InitMqtt()
{
	mqttClient.onConnect(OnMqttConnect);
	mqttClient.onDisconnect(OnMqttDisconnect);

	mqttClient.onSubscribe(OnMqttSubscribe);
	mqttClient.onUnsubscribe(OnMqttUnsubscribe);

	//mqttClient.onMessage(OnMqttReceived);
	mqttClient.onPublish(OnMqttPublish);

	mqttClient.setServer(MQTT_HOST, MQTT_PORT);
  ConnectToMqtt();
}
