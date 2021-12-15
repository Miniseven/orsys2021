/*
    LCD_I2C - Arduino library to control a 16x2 LCD via an I2C adapter based on PCF8574

    Copyright(C) 2020 Blackhack <davidaristi.0504@gmail.com>

    This program is free software : you can redistribute it and /or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.If not, see < https://www.gnu.org/licenses/>.
*/
#define PASVOLT (float)(5.0F / 1024.0F)
#include <LCD_I2C.h>

LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

void setup()
{
  
    lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
                 // this stop the library(LCD_I2C) from calling Wire.begin()
    lcd.backlight();
    lcd.print("Voltmetre Multimetre");
    pinMode(INT0, INPUT_PULLUP);
    attachInterrupt(INT0, changeType , RISING);
    
}
volatile bool isVoltOrOhm=false;
void loop()
{
    if(isVoltOrOhm){showVoltage();}
    else{showRes();}
    delay(1000);
}

void changeType()
 {isVoltOrOhm=!isVoltOrOhm;}
 
void showVoltage()
{unsigned int palier = analogRead(A0);
  float pasSortie=33.5F/5.0F;
  float tensionIn=palier * PASVOLT* pasSortie;
  lcd.setCursor(8,1);
  lcd.print("       ");
  lcd.setCursor(8,1);
  lcd.print(tensionIn);
  lcd.print("V");
  delay(200);}
    
void showRes()
{unsigned int palier = analogRead(A1);
  lcd.setCursor(8,1);
  lcd.print("       ");
  lcd.setCursor(8,1);lcd.print("res");}
