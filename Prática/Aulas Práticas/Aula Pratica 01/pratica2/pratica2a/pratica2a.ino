  /*
Simula um semáforo (farol) de trânsito com os leds das cores tradicionais (verde, amarelo e vermelho), e os respectivos tempos que permanecem acessos). 
*/
const int ledVerde = 8; // Pino digital utilizado pelo led verde
const int ledAmarelo = 9; // Pino digital utilizado pelo led amarelo
const int ledVermelho = 10; // Pino digital utilizado pelo led vermelho

void setup() {
    pinMode(ledVerde,OUTPUT); // Define o pino como saída
    pinMode(ledAmarelo,OUTPUT); // Define o pino como saída
    pinMode(ledVermelho,OUTPUT); // Define o pino como saída
}

void loop() {
    digitalWrite(ledVerde,HIGH); // Acende o led verde
    delay(2000); // Intervalo de 2 segundos
    digitalWrite(ledVerde,LOW); // Apaga o led verde
    digitalWrite(ledAmarelo,HIGH); // Acende o led amarelo
    delay(1000); // Intervalo de 1 segundo
    digitalWrite(ledAmarelo,LOW); // Apaga o led amarelo
  
    digitalWrite(ledVermelho,HIGH); // Acende o led vermelho
    delay(2000); // Intervalo de 2 segundos
    digitalWrite(ledVermelho,LOW); // Apaga o led vermelho
    delay(1000); // Intervalo de 1 segundo

    digitalWrite(ledVerde,HIGH); // Acende o led verde
    digitalWrite(ledAmarelo,HIGH); // Acende o led amarelo
    digitalWrite(ledVermelho,HIGH); // Acende o led vermelho
    delay(3000); // Intervalo de 3 segundos
  
    digitalWrite(ledVerde,LOW); // Apaga o led verde
    digitalWrite(ledAmarelo,LOW); // Apaga o led amarelo
    digitalWrite(ledVermelho,LOW); // Apaga o led vermelho
    delay(1000); // Intervalo de 1 segundo
}
