
#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

void setup()
{
  lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
  // this stop the library(LCD_I2C) from calling Wire.begin()
  lcd.backlight();
  lcd.print("Voltmetre 33.5V");
}

void loop()
{
  unsigned int palier = analogRead(A0);
 
  float pasSortie = 33.5F / 5.0F
  //avec pont diviseur 
  //33.5Vmax!----!1K!--!4.7K!--+----!GND
  //                           !
  //                         A0 arduino                    
  float tensionIn = palier * PASVOLT * pasSortie
  //clear de la section affichée                    
  lcd.setCursor(8, 1);
  lcd.print("        ");
  //repositionnement + affichage
  lcd.setCursor(8, 1);
  lcd.print(tensionIn);
  lcd.print("V");
  delay(800);
}
