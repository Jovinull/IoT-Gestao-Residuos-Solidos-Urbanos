#include <WiFi.h>
#include <PubSubClient.h>
#include <Ultrasonic.h>
#include <DHT.h>

// Credenciais da rede Wi-Fi
const char* ssid = "Jovino";
const char* password = "benicio123";
// Endereço do servidor MQTT
const char* mqtt_server = "broker.hivemq.com";

// Objetos para gerenciar a conexão Wi-Fi e MQTT
WiFiClient espClient;
PubSubClient client(espClient);
// Variável para controle do tempo da última mensagem
unsigned long lastMsg = 0;
// Buffer para armazenar as mensagens MQTT
#define MSG_BUFFER_SIZE (50)
char msg[MSG_BUFFER_SIZE];

// Pinos para o sensor ultrassônico
int echo = 12;
int trig = 14;
// Objeto do sensor ultrassônico
Ultrasonic ultrassom(trig, echo);

// Pino para o LED
int pin_led = 2;

// Variáveis para medição e controle do sensor ultrassônico
unsigned long tempo;
float distancia;
float Tmax = 50;

// Configuração do sensor DHT
#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Função para configurar a conexão Wi-Fi
void setup_wifi() {
  delay(10);
  
  // Configuração do modo Wi-Fi e início da conexão
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // Aguarda até a conexão ser estabelecida
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  // Inicialização da semente para geração de números aleatórios
  randomSeed(micros());
}

// Função para reconectar ao servidor MQTT em caso de desconexão
void reconnect() {
  while (!client.connected()) {
    // Geração de um ID de cliente único
    String clientId = "JOVINO_MQTT";
    clientId += String(random(0xffff), HEX);
    
    // Tenta reconectar ao servidor MQTT
    if (client.connect(clientId.c_str())) {
      // Subscreve ao tópico para receber mensagens
      client.subscribe("jovino/publisher");
    } else {
      // Aguarda antes de tentar novamente
      delay(5000);
    }
  }
}

// Função para realizar a leitura do sensor ultrassônico e publicar a distância no tópico MQTT
void ultrassonico() {
  distancia = ultrassom.Ranging(CM);

  // Cálculo da percentagem em relação à distância máxima
  float percentMax = (distancia / Tmax) * 100;

  // Formatação da mensagem e publicação no tópico MQTT
  sprintf(msg, "%f", percentMax);
  client.publish("jovino/sommm", msg);
  delay(100);
}

// Callback chamada quando uma mensagem MQTT é recebida
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensagem recebida [");
  Serial.print(topic);
  Serial.print("] ");

  // Impressão do conteúdo da mensagem recebida
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }

  Serial.println();

  // Controle do LED com base na mensagem recebida
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

// Função para realizar a leitura do sensor DHT e publicar umidade e temperatura nos tópicos MQTT correspondentes
void umidade_temp() {
  // Leitura da umidade
  float umidade = dht.readHumidity();

  // Formatação da mensagem e publicação no tópico MQTT
  sprintf(msg, "%f", umidade);
  client.publish("jovino/umidade", msg);
  
  // Leitura da temperatura e cálculo do índice de calor
  float temperatura = dht.readTemperature();
  float hic = dht.computeHeatIndex(temperatura, umidade, false);

  // Formatação da mensagem e publicação no tópico MQTT
  sprintf(msg, "%f", hic);
  client.publish("jovino/temperatura", msg);
}

// Configurações iniciais: pinos, conexão Wi-Fi e servidores MQTT
void setup() {
  // Configuração dos modos dos pinos
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(pin_led, INPUT);

  // Configuração da conexão Wi-Fi, do servidor MQTT e do callback
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

// Loop principal: leitura dos sensores, verificação da conexão MQTT e execução do loop do cliente MQTT
void loop() {
  // Leitura do sensor ultrassônico
  ultrassonico();
  
  // Leitura do sensor DHT
  umidade_temp();

  // Verificação da conexão MQTT e execução do loop do cliente MQTT
  if (!client.connected()) {
    reconnect();
  }
  
  client.loop();
  
  // Aguarda antes de realizar a próxima iteração do loop
  delay(500);
}
