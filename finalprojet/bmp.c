#include "bmp.h"
#include "struct.h"
//instance d'accès au composant par librairie
Adafruit_BMP085 bmp;
unit64_t initialPressure=0;

void loopBPM(){
  datas.meteo.pression = bmp.readPressure();
  datas.geographie.altitude = bmp.readAltitude(initialPressure);
}

void setupBMP(){
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
    while (1) {}
  }
  else {
    initialPressure = bmp.readPressure();
}
