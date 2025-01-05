// Definindo o pino
const int ledPin = 13;
#include <SevSeg.h>
SevSeg setSeg;
int conta = 0;
int delayS = 500;
int delayO = 2000;

byte pinosDisplay[] = { 2, 3, 4, 5, 6, 7, 8 };

// Função setup é executada uma vez quando o Arduino é ligado
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  // Configura o pino do LED como saída
  byte numDigitos = 1;
  byte digitPinos[] = {};
  bool resistoresSegmentos = true;
  setSeg.begin(COMMON_CATHODE, numDigitos, digitPinos, pinosDisplay, resistoresSegmentos);
  setSeg.setBrightness(90);

for (int i = 2 ; i <= 7 ; i++){
  digitalWrite(i,1);
  }

}

// Função loop é executada repetidamente
void loop() {

  
  Serial.print(conta);
  setSeg.setNumber(conta);
  setSeg.refreshDisplay();
  
  for (int j = 0; j < 3; j++) {
    digitalWrite(ledPin, HIGH);  // Acende o LED
    delay(delayS);                  // Mantém aceso por 0.5 segundos
    digitalWrite(ledPin, LOW);   // Apaga o LED
    delay(500);                  // Mantém apagado por 0.5 segundos
  }
  // Sinal 'O' (3 traços)
  for (int j = 0; j < 3; j++) {
    digitalWrite(ledPin, HIGH);  // Acende o LED
    delay(delayO);                 // Mantém aceso por 1.5 segundos
    digitalWrite(ledPin, LOW);   // Apaga o LED
    delay(500);                  // Mantém apagado por 0.5 segundos
  }
  // Sinal 'S' (3 pontos)
  for (int j = 0; j < 3; j++) {
    digitalWrite(ledPin, HIGH);  // Acende o LED
    delay(delayS);                 // Mantém aceso por 0.5 segundos
    digitalWrite(ledPin, LOW);   // Apaga o LED
    delay(500);                  // Mantém apagado por 0.5 segundos
  }
  conta += 1;
  if (conta > 9){
    conta = 1;
  }
}