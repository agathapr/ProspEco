#include <WiFi.h>
#include <PubSubClient.h>

// Configurações da rede WiFi (simuladas)
const char* ssid = "Seu_SSID";
const char* password = "Sua_Senha";

// Configurações do broker MQTT
const char* mqtt_server = "broker.hivemq.com";
WiFiClient espClient;
PubSubClient client(espClient);

struct Device {
    int pin;
    int value;
};

Device ldr;
Device led;

void setup_wifi();
void reconnect();
void readLDR(Device* ldr);
void controlLED(Device* led, int lightLevel);

void setup() {
    Serial.begin(115200);
    
    ldr.pin = A0;
    ldr.value = 0;
    
    led.pin = 13;
    pinMode(led.pin, OUTPUT);
    
    setup_wifi();
    client.setServer(mqtt_server, 1883);
}

void loop() {
    if (!client.connected()) {
        reconnect();
    }
    client.loop();
    
    readLDR(&ldr);
    
    char msg[50];
    sprintf(msg, "%d", ldr.value);
    client.publish("sensor/light", msg);
    
    controlLED(&led, ldr.value);
    
    delay(1000);
}

void setup_wifi() {
    delay(10);
    Serial.println();
    Serial.print("Simulando conexão a ");
    Serial.println(ssid);
    
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi simulado conectado");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void reconnect() {
    while (!client.connected()) {
        Serial.print("Tentando conexão MQTT...");
        if (client.connect("ESP32Client")) {
            Serial.println("conectado");
        } else {
            Serial.print("falhou, rc=");
            Serial.print(client.state());
            Serial.println(" tenta novamente em 5 segundos");
            delay(5000);
        }
    }
}

void readLDR(Device* ldr) {
    ldr->value = analogRead(ldr->pin);
    Serial.print("Nível de luz: ");
    Serial.println(ldr->value);
}

void controlLED(Device* led, int lightLevel) {
    if (lightLevel < 500) {
        digitalWrite(led->pin, HIGH); // Liga o LED
    } else {
        digitalWrite(led->pin, LOW); // Desliga o LED
    }
}
