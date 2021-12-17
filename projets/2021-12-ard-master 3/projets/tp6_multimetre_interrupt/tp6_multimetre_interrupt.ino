#define PASVOLT (float)(5.0F / 1024.0F)
#include <LCD_I2C.h>
LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according
void setup()
{
  lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
  // this stop the library(LCD_I2C) from calling Wire.begin()
  lcd.backlight();
  lcd.print("Voltmetre Multimetre");
  attachInterrupt(INT0, changeType, RISING);
}
volatile bool isVoltOrOhm = false;
void loop() {
  if (isVoltOrOhm) {
    showVoltage();
  }
  else {
    showRes();
  }
  delay(1000);

}
void changeType() {
  isVoltOrOhm = !isVoltOrOhm;
}
void showVoltage() {
  unsigned int palier = analogRead(A0);
  float pasSortie = 33.5F / 5.0F
  float tensionIn = palier * PASVOLT * pasSortie
                                      //clear de la section affichée
  lcd.setCursor(8, 1);
  lcd.print("        ");
  //repositionnement + affichage
  lcd.setCursor(8, 1);
  lcd.print(tensionIn);
  lcd.print("V");
}
#define R1 1000.0F
void showRes() {
    unsigned int palier = analogRead(A1);
    float tensionEnA1=palier * PASVOLT;
    float r2=R1*(5.0F/tensionEnA1)-R1;
    lcd.setCursor(8, 1);
    lcd.print("        ");
    //repositionnement + affichage
    lcd.setCursor(8, 1);
    lcd.print(r2);
}
