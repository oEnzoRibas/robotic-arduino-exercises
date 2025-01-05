/*
Faz a contagem numérica de 0 a 9 num display LCD de 7 segmentos. 
*/
#include <SevSeg.h>  // Adiciona a biblioteca “SevSeg" ao projeto
SevSeg setSeg;

 byte pinosDisplay[] = { 2, 3, 8, 7, 6, 5, 8, 9 };

void setup() {
  // Definido como 1 para exibição de um dígito
  byte numDigitos = 1;

  // Define pinos comuns ao usar display de vários dígitos. Deixado vazio, pois temos um display de um único dígito
  byte digitPinos[] = {};

  bool resistoresSegmentos = true;
  setSeg.begin(COMMON_CATHODE, numDigitos, digitPinos, pinosDisplay, resistoresSegmentos);
  setSeg.setBrightness(90);
}

void loop() {
  // Exibir números um por um com 2 segundos de atraso
  for (int i = 0; i <= sizeof(pinosDisplay)-1; i++) {
    digitalWrite(pinosDisplay[i], HIGH);
    delay(1000);
    setSeg.refreshDisplay();
    delay(1000);
  }
}
