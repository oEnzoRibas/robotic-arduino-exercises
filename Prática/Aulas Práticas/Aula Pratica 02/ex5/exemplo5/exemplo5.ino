
const int led = 06;

// Variável para contar o número de vezes que o LED piscou
int cont = 1;

// Pisca o LED três vezes
while (analogRead(A0) < 500) { // Verifica qual o valor retorna no pino analógico A0
    digitalWrite(led, HIGH); // Atribui nível lógico alto ao pino do LED, acendendo-    
    delay(1000); // Espera 1000 milissegundos (um segundo)
    digitalWrite(led, LOW); // Atribui nível lógico baixo ao pino do LED, apagando-    
    delay(1000); // Espera 1000 milissegundos (um segundo)
    cont++; // Incrementa o número de vezes que o LED piscou
}
Serial.println(cont); // Imprime o valor de cont no monitor serial
