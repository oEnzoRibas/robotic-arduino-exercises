#include <LiquidCrystal.h>
/*
Mostra a distância medida por um sensor ultrassônico. 
*/
int PinTrigger = 5;                           // Pino usado para disparar os pulsos do sensor
int PinEcho = 6;                              // pino usado para ler a saída do sensor
const float VelocidadeSom_mpors = 340;        // em metros por segundo
const float VelocidadeSom_mporus = 0.000340;  // em metros por microssegundo

// Inicializa o LCD com os pinos RS, RW, Enable e D4-D7
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);  // rs, enable, d1, d2, d3, d4

// Inicializa os pinos dos LEDs
int Y = 3;
int G = 2;
int R = 4;
float distM = 0;
float distC = 0;

void setup() {
  // Configura pino de Trigger como saída
  pinMode(PinTrigger, OUTPUT);
  // Configura pino de Trigger com nível baixo
  digitalWrite(PinTrigger, LOW);
  // configura pino ECHO como entrada
  pinMode(PinEcho, INPUT);
  // Inicializa a porta serial
  Serial.begin(9600);
  delay(100);

  lcd.begin(16, 2);  // Inicializa o LCD com 16 colunas e 2 linhas
  pinMode(G, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(R, OUTPUT);

  lcd.print("STARTING");
  delay(1000);
  lcd.clear();
}

void loop() {
  // Envia pulso para o disparar o sensor
  DisparaPulsoUltrassonico();
  // Mede o tempo de duração do sinal no pino de leitura(us)
  float TempEcho = pulseIn(PinEcho, HIGH);

  distM = CalculaDistancia(TempEcho);
  distC = CalculaDistancia(TempEcho * 100);

  // Serial.println("Distancia em metros: ");
  // Serial.println(distM);
  // Serial.println("Distancia em centimetros: ");
  // Serial.println(distC);
  // Aguarda 2 segundos antes de começar tudo de novo
  delay(1000);

lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distancia: ");
  lcd.print((distC / 100));
  lcd.print("m");

  if (distC > 100) {
    
    lcd.setCursor(1, 1);
    lcd.print("SEGURO");

    digitalWrite(G, HIGH);
    digitalWrite(Y, LOW);
    digitalWrite(R, LOW);
  } else if (distC < 100 && distC > 50) {
    lcd.setCursor(1, 1);
    lcd.print("CUIDADO");

    digitalWrite(G, LOW);
    digitalWrite(Y, HIGH);
    digitalWrite(R, LOW);
  } else if (distC < 50 && distC > 10) {
    lcd.setCursor(1, 1);
    lcd.print("VAI BATER");

    digitalWrite(G, LOW);
    digitalWrite(Y, LOW);
    digitalWrite(R, HIGH);
  } else if (distC < 10) {
    lcd.setCursor(1, 1);
    lcd.print("BATEU");

    digitalWrite(G, HIGH);
    digitalWrite(Y, HIGH);
    digitalWrite(R, HIGH);
  }
}
void DisparaPulsoUltrassonico() {
  // Para fazer o HC-SR04 enviar um pulso ultrassónico, nós temos
  // que enviar para o pino de trigger um sinal de nível alto
  // com pelo menos 10us de duração
  digitalWrite(PinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(PinTrigger, LOW);
}

// Função para calcular a distância em metros  d = vt or t
float CalculaDistancia(float tempo_us) {
  return (tempo_us * VelocidadeSom_mporus / 2);
}
