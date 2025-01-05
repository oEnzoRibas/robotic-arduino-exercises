#include <LiquidCrystal.h>

// Inicializa o LCD com os pinos RS, RW, Enable e D4-D7
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);  // rs, enable, d1, d2, d3, d4
#include <LiquidCrystal.h>

void setup() {
  lcd.begin(16, 2);  // Inicia o LCD com 16 colunas e 2 linhas
}

void loop() {
  // Sequência crescente
  for (int i = 1; i <= 9; i++) {
    lcd.clear();
    lcd.setCursor(0,0);
    for (int j = 0; j < i-1; j++) {
      lcd.print(i-1);
    }
    lcd.setCursor(0, 1);
    for (int j = 0; j < i; j++){
      lcd.print(i);
    }
    delay(1000);  // Atraso de 1 segundo
  }
  // Sequência decrescente
    for (int i = 8; i >= 1; i--){
    lcd.clear();
    lcd.setCursor(0,0);
    for (int j = 0; j < i+1; j++) {
      lcd.print(i+1);
    }
    lcd.setCursor(0, 1);
    for (int j = 0; j < i; j++){
      lcd.print(i);
    }
    delay(1000);  // Atraso de 1 segundo
  }
}