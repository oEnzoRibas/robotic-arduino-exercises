byte g = 10; //LED Verde
byte y = 11; //LED Amarelo
byte r = 12; //LED Vermelho

byte pinosDisplay[] = { 2, 3, 4, 5, 6, 7, 8 };

byte pedestreG = 9;
byte pedestreR = 13;

int buttonPin = 1;  // define o pino do botão
int estadoButton;  // Armazena o estado atual do botão

int digitosValue[11][8] = {
  { 0, 0, 0, 0, 0, 0, 0 },  // 0
  { 0, 1, 1, 0, 0, 0, 0 },  // 1
  { 1, 1, 0, 1, 1, 0, 1 },  // 2
  { 1, 1, 1, 1, 0, 0, 1 },  // 3
  { 0, 1, 1, 0, 0, 1, 1 },  // 4
  { 1, 0, 1, 1, 0, 1, 1 },  // 5
  { 1, 0, 1, 1, 1, 1, 1 },  // 6
  { 1, 1, 1, 0, 0, 0, 0 },  // 7
  { 1, 1, 1, 1, 1, 1, 1 },  // 8
  { 1, 1, 1, 1, 0, 1, 1 },  // 9
  { 0, 0, 0, 0, 0, 0, 0,},  // Desligado
};


void setup() {
  // define os pinos como output
  for (int i = 0; i < 14; i++) {
    pinMode(pinosDisplay[6], OUTPUT);
  }
  for (int i = 2; i <14; i++){
  pinMode(i,OUTPUT); 
  }
  
  pinMode(buttonPin, INPUT);  // Define o pino do botão como entrada
  digitalWrite(g, HIGH);


}

void loop() {
  // Lê o estado atual do botão
  estadoButton = digitalRead(buttonPin);

  // Acende apenas o led VERDE Semáforo
  digitalWrite(g, HIGH);
  digitalWrite(y, LOW);
  digitalWrite(r, LOW);
  digitalWrite(pedestreR, HIGH);
  digitalWrite(pedestreG, LOW);


  // Verifica se o botão foi apertado
  if (estadoButton == HIGH) {
    delay(50); // Debounce delay
    
    digitalWrite(g, LOW);
    digitalWrite(y, HIGH);
    digitalWrite(r, LOW);
    delay(2000);  // Delay de 2 segundos
    
    digitalWrite(g, LOW);
    digitalWrite(y, LOW);
    digitalWrite(r, HIGH);
    digitalWrite(pedestreR, LOW);
    digitalWrite(pedestreG, HIGH);


    for (int i = 9; i > 0 ; i--){
      printDig(i);
      
      if(i < 3){
        digitalWrite(pedestreG, LOW);
        delay(500);
        digitalWrite(pedestreG, HIGH);
        delay(500);
      }else {
        delay(1000);  // Delay de 1 segundos 
      }
    }
    printDig(10);
  }
}

void printDig(int dig) {
  // varre o array de pinos, para ligar cada numero na ordem do array
  for (int i = 0; i < 8; i++) {
    digitalWrite(pinosDisplay[i], digitosValue[dig][i]);
  }
}
