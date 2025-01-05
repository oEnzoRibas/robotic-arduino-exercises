byte pinosDisplay[] = { 2, 3, 4, 5, 6, 7, 8, 9 };
byte pinsLed[] = { 13, 12, 11, 10 };

int cont = 1; 

int digitosValue[16][8] = {
  { 0, 0, 0, 0, 0, 0, 0, 0 },  // 0
  { 0, 1, 1, 0, 0, 0, 0, 0 },  // 1
  { 1, 1, 0, 1, 1, 0, 1, 0 },  // 2
  { 1, 1, 1, 1, 0, 0, 1, 0 },  // 3
  { 0, 1, 1, 0, 0, 1, 1, 0 },  // 4
  { 1, 0, 1, 1, 0, 1, 1, 0 },  // 5
  { 1, 0, 1, 1, 1, 1, 1, 0 },  // 6
  { 1, 1, 1, 0, 0, 0, 0, 0 },  // 7
  { 1, 1, 1, 1, 1, 1, 1, 0 },  // 8
  { 1, 1, 1, 1, 0, 1, 1, 0 },  // 9
  { 1, 1, 1, 0, 1, 1, 1, 0 },  // A
  { 0, 0, 1, 1, 1, 1, 1, 0 },  // B
  { 1, 0, 0, 1, 1, 1, 0, 0 },  // C
  { 0, 1, 1, 1, 1, 0, 1, 0 },  // D
  { 1, 0, 0, 1, 1, 1, 1, 0 },  // E
  { 1, 0, 0, 0, 1, 1, 1, 0 }   // F
};

int binLedValue[16][4] = {
  { 0, 0, 0, 0 },  // 0
  { 0, 0, 0, 1 },  // 1
  { 0, 0, 1, 0 },  // 2
  { 0, 0, 1, 1 },  // 3
  { 0, 1, 0, 0 },  // 4
  { 0, 1, 0, 1 },  // 5
  { 0, 1, 1, 0 },  // 6
  { 0, 1, 1, 1 },  // 7
  { 1, 0, 0, 0 },  // 8
  { 1, 0, 0, 1 },  // 9
  { 1, 0, 1, 0 },  // 10
  { 1, 0, 1, 1 },  // 11
  { 1, 1, 0, 0 },  // 12
  { 1, 1, 0, 1 },  // 13
  { 1, 1, 1, 0 },  // 14
  { 1, 1, 1, 1 }   // 15
};

void setup() {
  // define os pinos como output
  for (int i = 0; i < 15; i++) {
    pinMode(pinosDisplay[i], OUTPUT);
  }
}

void loop() {
  
  printDig(cont);
  
  printBinDig(cont);
  
  delay(600);  
  
  cont++;
  
  if (cont > 15) {
    cont = 1;  // Resetar o contador após o valor 15
  }
}

void printDig(int dig) {
  // varre o array de pinos, para ligar cada numero na ordem do array
  for (int i = 0; i < 8; i++) {
    digitalWrite(pinosDisplay[i], digitosValue[dig][i]);
  }
}

void printBinDig(int dig) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(pinsLed[i], binLedValue[dig][i]);
  }
}
