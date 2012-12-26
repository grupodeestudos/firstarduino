#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(13, OUTPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Is we @ Sieve");
}
void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}

