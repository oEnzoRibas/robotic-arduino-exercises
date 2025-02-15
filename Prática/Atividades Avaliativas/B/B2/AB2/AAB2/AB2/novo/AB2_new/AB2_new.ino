#include <LiquidCrystal.h>

// Inicializa o LCD com os pinos RS, RW, Enable e D4-D7
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);  // rs, enable, d1, d2, d3, d4
int estadoButtonIn;
int estadoButtonRes;
int buttonPinIn = 3;
int buttonPinRes = 2;
int ultimoEstadoButtonRes = LOW; // Armazena o último estado do botão

int Y = 4;
int G = 5;
int R = 6;
  

bool parado = true; // Indica se o contador está parado
bool rodando = false;

int horas = 0;
int minutos = 0;
int segundos = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);  // Inicializa o LCD com 16 colunas e 2 linhas
  pinMode(buttonPinIn, INPUT);
  pinMode(buttonPinRes, INPUT);
  pinMode(G,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(R,OUTPUT);
  if (minutos > 1){
    digitalWrite(Y, HIGH);
  }
}

void loop() {
  estadoButtonIn = digitalRead(buttonPinIn);
  estadoButtonRes = digitalRead(buttonPinRes);

  Serial.print(estadoButtonRes);
  Serial.print(estadoButtonIn);

  // Leitura do botão de reinício
  if (estadoButtonRes == HIGH && ultimoEstadoButtonRes == LOW) {
    // Reinicia o cronômetro
    lcd.clear();
    lcd.print("RESETANDO");
    horas = 0;
    minutos = 0;
    segundos = 0;
    
    digitalWrite(Y, LOW);
    digitalWrite(G, LOW);
    digitalWrite(R, LOW);
    delay(500);
    lcd.clear();
    parado = true;
    rodando = false;

  }
  ultimoEstadoButtonRes = estadoButtonRes; // Atualiza o último estado do botão

  // Alterna entre iniciar e parar
  if (estadoButtonIn == HIGH) {

    if (rodando == false){
    rodando = true;
    parado = false;
    } else if (rodando == true){
      rodando = false;
      parado = true;
    }
    delay(200);  // Atraso para evitar múltiplas leituras do botão
  }

  // Se o cronômetro não estiver parado, incrementa o tempo
  if (rodando) {
    delay(1000);  // Atraso de 1 segundo
    segundos++;

    // Atualiza minutos e horas se necessário
    if (segundos >= 60) {
      segundos = 0;
      minutos++;
    }
    if (minutos >= 60) {
      minutos = 0;
      horas++;
    }
  } 

  if (segundos <= 10 && segundos > 0){
    digitalWrite(G, HIGH);
    digitalWrite(Y, LOW);
    digitalWrite(R, LOW);
  }else if (segundos > 10 && segundos < 20){
    digitalWrite(G, LOW);
    digitalWrite(Y, HIGH);
    digitalWrite(R, LOW);
  }else if(segundos > 20){
    digitalWrite(G, LOW);
    digitalWrite(Y, LOW);
    digitalWrite(R, HIGH);
  }
    // Exibe no LCD
    lcd.setCursor(3, 0);
    lcd.print("Cronometro");
    lcd.setCursor(4, 1);

    if (horas < 10) {
      lcd.print("0");
      lcd.print(horas);
    } else {
      lcd.print(horas);
    }
    lcd.print(":");
    if (minutos < 10) {
      lcd.print("0");
      lcd.print(minutos);
    } else {
      lcd.print(minutos);
    }
    lcd.print(":");
    if (segundos < 10) {
      lcd.print("0");
      lcd.print(segundos);
    } else {
      lcd.print(segundos);
    }
}
