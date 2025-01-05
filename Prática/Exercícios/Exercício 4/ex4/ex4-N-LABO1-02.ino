int ledPin = 6;             //Pino do LED
int sensorPin = 7;          //Pino do sensor de presença
int leitura = 0;            //Variável para armazenar a leitura do sensor
bool estadoSensor = false;  //Variável para armazenar o estado do sensor
int buttonPin = A2;          //Define buttonPin no pino digital 7
int estadoButton = 0;       //Variável responsável por armazenar o estado do botão (ligado/desligado)

void setup() {
  pinMode(ledPin, OUTPUT);    //Define ledPin (pino 10) como saída
  pinMode(buttonPin, INPUT);  //Define buttonPin (pino 7) como entrada
  Serial.begin(9600);         //Inicializa a comunicação serial
  pinMode(ledPin, OUTPUT);    //Define ledPin como saída
  pinMode(sensorPin, INPUT);  //Define sensorPin como entrada
}

void loop() {
  estadoButton = digitalRead(buttonPin);  //Lê o valor de buttonPin e armazena em estadoButton
  leitura = digitalRead(sensorPin);       //Realiza a leitura do sensor de presença

  if (leitura == HIGH and estadoButton == LOW) {  //Se leitura for igual a HIGH, o movimento foi detectado
    digitalWrite(ledPin, HIGH);                   //Aciona o LED
    if (estadoButton == HIGH) {
      Serial.println("Mafdagdgdgadagdagdagdgdgagd");  //Imprime a mensagem no monitor serial
      estadoSensor = false;                           //Altera o valor de estadoSensor para HIGH
    }
  }
}

