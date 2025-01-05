
const int led = 06;

// Variável para contar o número de vezes que o LED piscará
int cont;

// Pisca o LED três vezes
for (cont  = 1; cont <= 3; cont ++) {
    digitalWrite(led, HIGH); // Atribui nível lógico alto ao pino do LED, acendendo-    
    delay(1000); // Espera 1000 milissegundos (um segundo)
    digitalWrite(led, LOW); // Atribui nível lógico baixo ao pino do LED, apagando-    
    delay(1000); // Espera 1000 milissegundos (um segundo)
}
delay(5000); // Espera 5 segundos para piscar o LED de novo
