byte pinosDisplay[] = { 2, 3, 4, 5, 6, 7, 8, 9 };

int buttonPin = 12; // define o pino do botão
int cont = 1; // Contador inicia em 1
int digitosValue[6][8] = {
  { 0, 1, 1, 0, 0, 0, 0, 0 },  // 1
  { 1, 1, 0, 1, 1, 0, 1, 0 },  // 2
  { 1, 1, 1, 1, 0, 0, 1, 0 },  // 3
  { 0, 1, 1, 0, 0, 1, 1, 0 },  // 4
  { 1, 0, 1, 1, 0, 1, 1, 0 },  // 5
  { 1, 0, 1, 1, 1, 1, 1, 0 },  // 6
};
int estadoButton; // Armazena o estado atual do botão
int ultimoEstadoButton = LOW; // Armazena o ultimo estado do botão
bool parado = false; // Indica se o contador está parado

void setup() {
  pinMode(buttonPin, INPUT);  // Define o pino do botão como entrada

  // define os pinos como output
  for (int i = 0; i < 8; i++) {
    pinMode(pinosDisplay[i], OUTPUT);
  }
}

void loop() {
  // Lê o estado atual do botão
  estadoButton = digitalRead(buttonPin);

  // Verifica se o botão foi apertado (saiu de LOW para HIGH)
  if (estadoButton == HIGH && ultimoEstadoButton == LOW) {

    /* Alterna entre iniciar e parar
    Se estava rodando, agora irá parar
    se estava parado, agora voltará a rodar
    */
    parado = !parado; 

    if (parado) { // se estiver parado e o botão apertado (já que estamos dentro do escopo do botão ==HIGH)
      cont = 1; // Reinicia o contador
    }

    delay(50);  // Pequeno delay para debounce
  }

  // Atualiza o último estado do botão
  ultimoEstadoButton = estadoButton;  // se os dois forem HIGH, ele interpretará como 1 unico aperto

  // Se não estiver parado, continua a contagem
  if (!parado) {
    printDig(cont);
    cont++;
    
    if (cont > 6) { // range de contagem
      cont = 1;
    }
    
    delay(20);  // Delay para ver a mudança no display
  }
}

void printDig(int dig) {
  // varre o array de pinos, para ligar cada numero na ordem do array
  for (int i = 0; i < 8; i++) {
    digitalWrite(pinosDisplay[i], digitosValue[dig-1][i]);
  }
}
