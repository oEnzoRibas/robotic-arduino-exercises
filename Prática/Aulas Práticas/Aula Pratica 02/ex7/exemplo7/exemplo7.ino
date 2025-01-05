/*
Mostra mensagens num display de 16x2. 
*/
/*
Faz a contagem numérica de 0 a 9 num display LCD de 7 segmentos. 
*/
#include <SevSeg.h> // Adiciona a biblioteca “SevSeg" ao projeto
SevSeg setSeg;

void setup() {
   // Definido como 1 para exibição de um dígito 
   byte numDigitos = 1;
 
   // Define pinos comuns ao usar display de vários dígitos. Deixado vazio, pois temos um display de um único dígito      
   byte digitPinos[] = {}; 

   // Define as conexões de pinos do Arduino na ordem: A, B, C, D, E, F, G, DP 
   byte pinosDisplay[] = {3, 4, 5, 6, 7, 8, 9, 10}; 
   bool resistoresSegmentos = true;


   setSeg.begin(COMMON_CATHODE, numDigitos, digitPinos, pinosDisplay, resistoresSegmentos);
   setSeg.setBrightness(90);
} 

void loop() { 
   // Exibir números um por um com 2 segundos de atraso
   for(int i = 0; i <= 9; i++) {
        setSeg.setNumber(i);
        setSeg.refreshDisplay(); 
        delay(2000);
   }
}
