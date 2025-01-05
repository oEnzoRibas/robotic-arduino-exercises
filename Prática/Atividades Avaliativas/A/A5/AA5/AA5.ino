int ledY = 8;        // Pino do LED Y
int ledR = 9;        // Pino do LED R
int sensorPin = 11;  // Pino do sensor de presença
int leitura = 1;     // Variável para armazenar a leitura do sensor
int buttonPin = 10;  // Define buttonPin no pino digital 8
int estadoButton;    // Variável para armazenar o estado do botão
int cont = 0;

void setup() {
  Serial.begin(9600);          // Inicializa a comunicação serial
  pinMode(buttonPin, INPUT);  // Define o pino do botão como entrada
  pinMode(ledY, OUTPUT);       // Define ledPin como saída
  pinMode(ledR, OUTPUT);       // Define ledPin como saída
  pinMode(sensorPin, INPUT);   // Define sensorPin como entrada
}

void loop() {
  estadoButton = digitalRead(buttonPin);  // Lê o valor de buttonPin e armazena em estadoButton
  leitura = digitalRead(sensorPin);       // Realiza a leitura do sensor de presença

  if (leitura == HIGH) {       // Sensor detecta presença

    cont++;
    digitalWrite(ledR, HIGH);  // Acende o LED Vermelho
    Serial.println("DETECÇÃO");     // Imprime um texto
    Serial.println(cont);

    for (int i = 0; i < 4; i++) {
      digitalWrite(ledY, HIGH);  // Acende o LED Amarelo
      delay(500);
      digitalWrite(ledY, LOW);  // Apaga o LED Amarelo
      delay(500);
    }
  }
  if (estadoButton == HIGH) {  // Se o botão está pressionado
    digitalWrite(ledR, LOW);   // Apaga o LED, independentemente da presença
    cont = 0;
    Serial.println("BOTAO ON");
  }
  // Serial.println("estadoButton");
  // Serial.println(estadoButton);
  // Serial.println("leitura");
  // Serial.println(leitura);
  //  delay(1000); // Adiciona um pequeno delay para evitar leituras muito rápidas
}
