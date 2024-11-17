void ConnectWiFi()
{
   Serial.println("");
   WiFi.mode(WIFI_STA);
   WiFi.setHostname(MQTT_CLIENT);
   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
   if(USE_STATIC_IP) WiFi.config(ip, gateway, subnet);
   while (WiFi.status() != WL_CONNECTED) 
   { 
     delay(100);  
     Serial.print('.'); 
   }
 
   Serial.println("");
   Serial.print("Iniciado STA:\t");
   Serial.println(WIFI_SSID);
   Serial.print("IP address:\t");
   Serial.println(WiFi.localIP());
}

void WiFiEvent(WiFiEvent_t event)
{
	Serial.printf("[WiFi-event] event: %d\n", event);
}

char* getAttributes() {
    String payloadAttr = "";
    StaticJsonDocument<300> jsonAttr;
    jsonAttr["ClientName"] = MQTT_CLIENT;
    jsonAttr["IP"] = WiFi.localIP().toString();
    jsonAttr["MAC"] = WiFi.macAddress();
    jsonAttr["HostName"] = MQTT_CLIENT;
    jsonAttr["ConnectedSSID"] = WIFI_SSID;
    jsonAttr["RSSI"] = WiFi.RSSI();
	serializeJson(jsonAttr, payloadAttr);
	return (char*)payloadAttr.c_str();
}