
#include <LiquidCrystal.h>

// Inicializa o LCD com os pinos RS, RW, Enable e D4-D7
LiquidCrystal lcd(12, 13, 7, 6, 5, 4);  // rs, enable, d1, d2, d3, d4
int estadoButtonIn;
int estadoButtonRes;
int buttonPinIn = 10;
int buttonPinRes = 11;
int cont = 0;
int Y = 2;
int G = 3;
int R = 8;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);  // Inicia o LCD com 16 colunas e 2 linhas
  pinMode(buttonPinIn, INPUT);
  pinMode(buttonPinRes, INPUT);
}

void loop() {
  estadoButtonIn = digitalRead(buttonPinIn);
  estadoButtonRes = digitalRead(buttonPinRes);

  Serial.print(estadoButtonRes);
  Serial.print("heksajd");

  // Variáveis para horas, minutos e segundos
  int horas = 0;
  int minutos = 0;
  int segundos = 0;

  // Cronômetro

  lcd.clear();
  while (estadoButtonIn && !estadoButtonRes) {

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

    // Exibe no LCD
    lcd.setCursor(0, 0);
    lcd.print("Cronometro");
    lcd.setCursor(0, 1);

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

    // // Lê o estado do botão novamente
    if (estadoButtonRes == HIGH) {
      //lcd.clear();
      minutos = 0;
      segundos = 0;
      horas = 0;
    }


    delay(10);  // Atraso de 1 segundo
  }
}
