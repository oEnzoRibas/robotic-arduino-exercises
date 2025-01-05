/*
Liga um LED por um segundo e depois apaga por um segundo, repetidamente. A constante pino_LED é o número do pino ao qual o LED on-board está conectado. 
*/
const int pino_LED = 13;

void setup() {
    // Inicializa o pino digital pin_LED como saída (output).
    pinMode(pino_LED, OUTPUT);
}
// A função loop é executada repetidamente até que se desenergize a placa
void loop() {
    digitalWrite(pino_LED, HIGH); // liga o LED (HIGH é nível alto de voltagem)
    delay(1000); // espera de um segundo (1000 = 1s)
    digitalWrite(pino_LED, LOW); // desliga o LED (LOW é nível baixo de voltagem)
    delay(1000);
}