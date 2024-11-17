// Variables para la conexion a la wifi
const char* WIFI_SSID     = "HUAWEI-061L7A";
const char* WIFI_PASSWORD = "Rf7FEed3GM";

// Variables del broker de MQTT (Mosquitto en HA)
const IPAddress MQTT_HOST(192, 168, 3, 56);
const int MQTT_PORT = 1883;
const char* MQTT_USER = "usermqtt";
const char* MQTT_PASSWORD = "secret";
const char* MQTT_CLIENT = "DHT11MODULO01";
const char* MQTT_TOPIC = "home/sensors/DHT11MODULO01";
const char* MQTT_TOPIC_ATTR = "home/sensors/DHT11MODULO01/attributes";
const int MQTT_PUB_DELAY = 10000;
const bool MQTT_PUB_ATTR = true;

// Si deseamos tener una dirección IP fija en nuestro sensor
const bool USE_STATIC_IP = false;
IPAddress ip(192, 168, 3, 71);
IPAddress gateway(192, 168, 3, 1);
IPAddress subnet(255, 255, 255, 0);

