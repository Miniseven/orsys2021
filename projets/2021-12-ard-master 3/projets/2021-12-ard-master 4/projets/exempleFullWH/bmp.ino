#include <Wire.h>
#include <Adafruit_BMP085.h>
uint16_t initialPressure=0;
Adafruit_BMP085 bmp;
void setupBMP() {
  bmp.begin();
  initialPressure=bmp.readPressure();
}
void loopBMP(){
  s.meteo.pressure=bmp.readPressure();
  s.geo.alt=bmp.readAltitude(initialPressure);
}
