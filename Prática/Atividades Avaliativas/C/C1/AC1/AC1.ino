#include <VarSpeedServo.h>

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

int i = 90; // graus de rotação da base
bool aux = true; // define qual o sentido da rotação
bool ajuste = false; // indica se já foi feito o ajuste após detectar presença
bool segurando = false; // indica se a garra está segurando um objeto

void setup() {

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

  Serial.print("AUX ");
  Serial.println(aux);
  Serial.print("GRAUS ");
  Serial.println(i);

  Serial.print("SEGURANDO ");
  Serial.println(segurando);
  Serial.print("AJUSTO ");
  Serial.println(ajuste);

 // rotaciona a base de um lado para o outro
  servo_base.slowmove(i, 30);
  delay(100);

// faz a mudança de sentido da rotação ao chegar no limite
  if (i >= 180) {
    aux = false;
  } else if (i <= 1) {
    aux = true;
  }
// incrementa a rotação do motor em 10 graus;
  if (aux) {
    i += 10;
  } else {
    i -= 10;
  }

  if (segurando) { // caso esteja segurando
    delay(100);

    // se estiver em uma das extremidades
    if (i <= 1 || i >= 180 ){

      if(aux){ // se estava incrementando, vai solta no menor grau de rotação
      servo_base.slowmove(1,30);
      delay(500);
      servo_altura.slowmove(90,30);
      delay(500);
      servo_altura.slowmove(120,30)
      delay(300);
      servo_garra.slowmove(120, 30);
      Serial.println("SOLTANDO");
      delay(1000);
      }
      else if (!aux){ // se esteva decrementando, via soltar no maior grau de rotação
      servo_base.slowmove(180,30);
      delay(500);
      servo_altura.slowmove(90,30);
      delay(500);
      servo_altura.slowmove(120,30)
      delay(300);
      servo_garra.slowmove(120, 30);
      Serial.println("SOLTANDO");
      delay(1000);
      }
      
      // reseta o braço
      i = 90;
      aux = true;
      ajuste = false;
      segurando = false;
  }
  }

// mede a distancia entre o sensor e um objeto
  // Envia pulso para o disparar o sensor
  DisparaPulsoUltrassonico();
  // Mede o tempo de duração do sinal no pino de leitura(us)
  float TempEcho = pulseIn(PinEcho, HIGH);

  distM = CalculaDistancia(TempEcho);
  distC = CalculaDistancia(TempEcho * 100);

  Serial.println("Distancia em centimetros: ");
  Serial.println(distC);

  if (!segurando) { // caso não estiver segurando
    if (distC <= 10) { //caso a distancia seja menor que 10 cm
      if (ajuste) { // ajuste começa como false para rodar mais uma vez e a inclinação ajustar
        delay(150);
        servo_garra.slowmove(120, 30); // abre a garra
        delay(1000);
        servo_altura.slowmove(180, 30); // levanta o braço
        delay(300);
        servo_inclinacao.slowmove(180, 30); // inclina o braço para frente
        delay(1000);
        servo_garra.slowmove(1, 30); // fecha a garra
        delay(300);
        servo_inclinacao.slowmove(10, 30); //inclina o braco para trás
        delay(2500);
        segurando = true; // define segurando como verdadeiro
        Serial.println("ESTÁ SEGURANDO");
      }
      delay(500);
      ajuste = true;
    }
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
