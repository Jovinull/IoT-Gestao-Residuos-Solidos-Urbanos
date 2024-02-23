#include <WiFi.h>
#include <PubSubClient.h>
#include <Ultrasonic.h>
#include <DHT.h>

const char* ssid = "Jovino";
const char* password = "benicio123";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (50)
char msg[MSG_BUFFER_SIZE];

int echo = 12;
int trig = 14;
Ultrasonic ultrassom(trig, echo);

int pin_led = 2;

unsigned long tempo;
float distancia;
float Tmax = 50;

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup_wifi() {
  delay(10);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  randomSeed(micros());
}

void reconnect() {
  while (!client.connected()) {
    String clientId = "JOVINO_MQTT";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      client.subscribe("jovino/publisher");     } else {
      delay(5000);
    }
  }
}

void ultrassonico() {
  distancia = ultrassom.Ranging(CM);

  float percentMax = (distancia / Tmax) * 100;

  sprintf(msg, "%f", percentMax);
  client.publish("jovino/sommm", msg);
  delay(100);
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensagem recebida [");
  Serial.print(topic);
  Serial.print("] ");

  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }

  Serial.println();

  if ((char)payload[0] == 'L') {
    digitalWrite(pin_led, HIGH);
    snprintf (msg, MSG_BUFFER_SIZE, "O LED está aceso");
    Serial.print("Publica mensagem: ");
    Serial.println(msg);
    client.publish("jovino/led", msg);
  }

  if ((char)payload[0] == 'l') {
    digitalWrite(pin_led, LOW);
    snprintf (msg, MSG_BUFFER_SIZE, "O LED está apagado");
    Serial.print("Publica mensagem: ");
    Serial.println(msg);
    client.publish("jovino/led", msg);
  }
}

void umidade_temp() {
  float umidade = dht.readHumidity();

  sprintf(msg, "%f", umidade);
  client.publish("jovino/umidade", msg);
  
  float temperatura = dht.readTemperature();
  float hic = dht.computeHeatIndex(temperatura, umidade, false);
  sprintf(msg, "%f", hic);
  client.publish("jovino/temperatura", msg);
}

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(pin_led, INPUT);

  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {

  ultrassonico();
  umidade_temp();

  if (!client.connected()) {
    reconnect();
  }
  
  client.loop();
  delay(500);
}
