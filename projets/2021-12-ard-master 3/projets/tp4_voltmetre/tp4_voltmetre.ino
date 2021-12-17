#include <LiquidCrystal.h>

#define PASVOLT (float)(5.0F / 1024.0F)

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Voltmetre 33.5V");
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int palier = analogRead(A0);
  Serial.print("valeur :\t");
  Serial.print(palier);
  Serial.print("\ttension :\t");
  float pasSortie=33.5F/5.0F
  float tensionIn=palier * PASVOLT* pasSortie
  Serial.print(tensionIn);
  Serial.print("V\n");

  lcd.setCursor(8,1);
  lcd.print("        ");
  lcd.setCursor(8,1);
  lcd.print(tensionIn);
  lcd.print("V");
  delay(800);
}
