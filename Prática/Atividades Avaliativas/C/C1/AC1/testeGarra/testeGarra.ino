#include <VarSpeedServo.h>

/*
Mostra a distância medida por um sensor ultrassônico. 
*/
int PinTrigger = 4;                           // Pino usado para disparar os pulsos do sensor
int PinEcho = 5;                              // pino usado para ler a saída do sensor
const float VelocidadeSom_mpors = 340;        // em metros por segundo
const float VelocidadeSom_mporus = 0.000340;  // em metros por microssegundo

float distM = 0;
float distC = 0;

VarSpeedServo servo_base;
VarSpeedServo servo_altura;
VarSpeedServo servo_inclinacao;
VarSpeedServo servo_garra;

const int pino_base = 11;
const int pino_inclinacao = 10;
const int pino_altura = 9;
const int pino_garra = 8;

int i = 0;
bool aux = true;
bool ajuste = false;
bool segurando = false;
bool solte = false;

void setup() {
  // put your setup code here, to run once:


  // Configura pino de Trigger como saída
  pinMode(PinTrigger, OUTPUT);
  // Configura pino de Trigger com nível baixo
  digitalWrite(PinTrigger, LOW);
  // configura pino ECHO como entrada
  pinMode(PinEcho, INPUT);
  // Inicializa a porta serial

  Serial.begin(9600);

  servo_base.attach(pino_base, 1, 180);
  servo_garra.attach(pino_garra, 1, 180);
  servo_inclinacao.attach(pino_inclinacao, 1, 180);
  servo_altura.attach(pino_altura, 1, 180);

  servo_base.slowmove(90, 30);
  servo_garra.slowmove(1, 30);
  servo_inclinacao.slowmove(90, 30);
  servo_altura.slowmove(90, 30);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(i);
  servo_garra.slowmove(1, 30);
  delay(300);
  servo_garra.slowmove(30, 30);
  delay(300);
  servo_garra.slowmove(60, 30);
  delay(300);
  servo_garra.slowmove(90, 30);
  delay(300);
  servo_garra.slowmove(120, 30);
  delay(300);
  i++;
}
