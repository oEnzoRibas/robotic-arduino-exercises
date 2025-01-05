byte g = 2; //LED Verde
byte y = 3; //LED Amarelo
byte r = 4; //LED Vermelho

int buttonPin = 12;  // define o pino do botão
int estadoButton;  // Armazena o estado atual do botão

void setup() {
  pinMode(buttonPin, INPUT);  // Define o pino do botão como entrada

  // define os pinos como output
  pinMode(g, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(r, OUTPUT);
}

void loop() {
  // Lê o estado atual do botão
  estadoButton = digitalRead(buttonPin);

  // Acende apenas o led VERDE
  digitalWrite(g, HIGH);
  digitalWrite(y, LOW);
  digitalWrite(r, LOW);

  // Verifica se o botão foi apertado
  if (estadoButton == HIGH) {
    digitalWrite(g, LOW);
    digitalWrite(y, HIGH);
    digitalWrite(r, LOW);
    delay(2000);  // Delay de 2 segundos
    digitalWrite(g, LOW);
    digitalWrite(y, LOW);
    digitalWrite(r, HIGH);
    delay(10000);  // Delay de 10 segundos
  }
}
