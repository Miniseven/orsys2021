#include <Adafruit_BMP085.h>

/*************************************************** 
  This is an example for the BMP085 Barometric Pressure & Temp Sensor

  Designed specifically to work with the Adafruit BMP085 Breakout 
  ----> https://www.adafruit.com/products/391

  These pressure and temperature sensors use I2C to communicate, 2 pins
  are required to interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

// Connect VCC of the BMP085 sensor to 3.3V (NOT 5.0V!)
// Connect GND to Ground
// Connect SCL to i2c clock - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 5
// Connect SDA to i2c data - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 4
// EOC is not used, it signifies an end of conversion
// XCLR is a reset pin, also not used here

Adafruit_BMP085 bmp;
#include <LCD_I2C.h>
LCD_I2C lcd(0x27, 16, 2); 

void setup() {
  lcd.begin();
  lcd.backlight();
  Serial.begin(9600);
  if (!bmp.begin()) {
    lcd.setCursor(5,0);
	lcd.print("Could not find a valid BMP085 sensor, check wiring!");
 delay(500);
	while (1) {}
  }
}
  
void loop() {

temperature();
Altitude();
AltitudeStand();
//RealAlt();
 
}
 void temperature()
 {
    lcd.setCursor(0,1);
    lcd.print(bmp.readTemperature());
    delay(500);

 }
 
void Altitude()
{
    lcd.setCursor(5,0);
    lcd.print(bmp.readPressure()/100000.0F);
    lcd.print(" Bar");
    delay(500);
}
    // Calculate altitude assuming 'standard' barometric
    // pressure of 1013.25 millibar = 101325 Pascal

void AltitudeStand(){

    lcd.setCursor(6,1);
    //lcd.print("Al= ");
    lcd.print(bmp.readAltitude());
    //lcd.println("m");
    //lcd.print("sl = ");
    lcd.print(bmp.readSealevelPressure());
    //lcd.println(" Pa");
}
  // you can get a more precise measurement of altitude
  // if you know the current sea level pressure which will
  // vary with weather and such. If it is 1015 millibars
  // that is equal to 101500 Pascals.

void RealAlt(){
    lcd.print("Real altitude = ");
    lcd.print(bmp.readAltitude(101500));
    lcd.println(" meters");
    
    lcd.println();
   // delay(500);
}
