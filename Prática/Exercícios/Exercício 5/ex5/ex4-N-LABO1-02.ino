int ledPin = 6;        // Pino do LED
int sensorPin = 12;     // Pino do sensor de presença
int leitura = 0;       // Variável para armazenar a leitura do sensor
int buttonPin = 8;    // Define buttonPin no pino digital 8
int estadoButton;  // Variável para armazenar o estado do botão

void setup() {
  Serial.begin(9600);        // Inicializa a comunicação serial
  pinMode(buttonPin, INPUT_PULLUP);  // Define o pino do botão como entrada
  pinMode(ledPin, OUTPUT);    // Define ledPin como saída
  pinMode(sensorPin, INPUT);  // Define sensorPin como entrada
}

void loop() {
  estadoButton = digitalRead(buttonPin);  // Lê o valor de buttonPin e armazena em estadoButton
  leitura = digitalRead(sensorPin);       // Realiza a leitura do sensor de presença

  if (leitura == HIGH) {         // Sensor detecta presença
    digitalWrite(ledPin, HIGH);  // Acende o LED
    Serial.println("LEITURA ON");
  }
  if (estadoButton == LOW) {   // Se o botão está pressionado
    digitalWrite(ledPin, LOW);  // Apaga o LED, independentemente da presença
    Serial.println("BOTAO ON");
  }
  Serial.println("estadoButton");
  Serial.println(estadoButton);
  Serial.println("leitura");
  Serial.println(leitura);
//  delay(1000); // Adiciona um pequeno delay para evitar leituras muito rápidas
}
