#include <ESP8266WiFi.h> //https://www.arduinolibraries.info/libraries/wi-fi
#include <PubSubClient.h> //https://www.arduinolibraries.info/libraries/pub-sub-client


//Definicoes e constantes
char ssid[] = "walrus0719a"; //nome da rede WiFi
char password[] = "12ab34cd56"; //senha da rede WiFI

const int SENSOR_PIN = A0; //terminal do sensor de temperatura e umidade

char BrokerURL[] = "broker.hivemq.com"; //URL do broker MQTT
char BrokerUserName[] = ""; //nome do usuario para autenticar no broker MQTT
char BrokerPassword[] = ""; //senha para autenticar no broker MQTT
char MQTTClientName[] = "mqtt-pub-sub"; //nome do cliente MQTT
int BrokerPort = 1883; //porta do broker MQTT

char Topico_01[] = "Projeto/Umidade"; //nome do topico 01

//Variaveis globais e objetos
WiFiClient espClient; //instancia o objeto espClient que pode se conectar a um endereço IP e porta de Internet especificados, conforme definido em clienteMQTT.connect()
PubSubClient clienteMQTT(espClient); //instancia o objeto clienteMQTT parcialmente inicializado cujo argumento eh o objeto para conectar na Internet

int umidade = 0;

//Funcoes definidas pelo usuário

//funcao para reconectar ao broker
void mqttReconnect() {
  while (!clienteMQTT.connected()) {
    Serial.println("Conectando-se ao broker MQTT...");
    Serial.println(MQTTClientName);
    if (clienteMQTT.connect(MQTTClientName, BrokerUserName, BrokerPassword)) {
      Serial.print(MQTTClientName);
      Serial.println(" conectado!");
    } else {
      Serial.print("failed, rc=");
      Serial.print(clienteMQTT.state());
      Serial.println(" tente novamente em 5 segundos.");
      delay(5000);
    }
  }
}
//funcao para transformar float em byte
void float2Bytes(float val,byte* bytes_array){
  // Create union of shared memory space
  union {
    float float_variable;
    byte temp_array[4];
  } u;
  // Overite bytes of union with float variable
  u.float_variable = val;
  // Assign bytes to input array
  memcpy(bytes_array, u.temp_array, 4);
}

//Setup
void setup() {
  clienteMQTT.setServer(BrokerURL, BrokerPort); //configura os detalhes do broker MQTT passando URL e porta
  //pinMode(SENSOR_PIN, INPUT);

  pinMode(LED_BUILTIN, OUTPUT); //configura o LED embutido da placa como saida

  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

//Loop
void loop() {
  if (!clienteMQTT.connected()) { //verifica se o cliente esta conectado ao broker
    mqttReconnect(); //se o cliente nao estiver conectado, tenta reconectar
  }
  clienteMQTT.loop(); //funcao necessaria para manter a conexao com o broker MQTT ativa e coletar as mensagens recebidas

  umidade = analogRead(SENSOR_PIN);
  float umidadef = map(umidade, 260, 560, 100.0, 0.0);
  if(umidadef < 0.0) umidadef = 0.0;
  if(umidadef > 100.0) umidadef = 100.0;
  //umidade++;
  char buf[10];
  sprintf(buf, "%.2f", umidadef);
  clienteMQTT.publish(Topico_01, buf); //publica um topico no broker
  Serial.printf("Umidade publicada com sucesso: %.2f  %d \n", umidadef, umidade);
  delay(5000); //Tempo colocado para teste
  //delay(300000) Tempo para implementação real
}