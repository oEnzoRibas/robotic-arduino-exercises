/*
Mostra a distância medida por um sensor ultrassônico. 
*/
int PinTrigger = 2; // Pino usado para disparar os pulsos do sensor
int PinEcho = 3; // pino usado para ler a saída do sensor
const float VelocidadeSom_mpors = 340; // em metros por segundo
const float VelocidadeSom_mporus = 0.000340; // em metros por microssegundo

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
}                                                                                                                                                                                      continua…
void loop() {
     // Envia pulso para o disparar o sensor
     DisparaPulsoUltrassonico();
     // Mede o tempo de duração do sinal no pino de leitura(us)
     float TempEcho = pulseIn(PinEcho, HIGH);
     Serial.println("Distancia em metros: ");
     Serial.println(CalculaDistancia(TempEcho));
     Serial.println("Distancia em centimetros: ");
     Serial.println(CalculaDistancia(TempEcho)*100);

     // Aguarda 2 segundos antes de começar tudo de novo
     delay(2000);
}

