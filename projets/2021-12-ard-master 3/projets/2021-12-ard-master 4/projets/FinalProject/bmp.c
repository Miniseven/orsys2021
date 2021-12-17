#include "bmp.h"
#include "struct.h"
//import des librairies pour le composant bmp 180/085
#include <Wire.h>
#include "lib/Adafruit_Sensor.h"
#include "lib/Adafruit_BMP085.h"
//instance d'acces au composant par librairie
struct Adafruit_BMP085 bmp;
uint64_t initialPressure=0;
void loopBMP(){
  //float bmpTemp = bmp.readTemperature();
  datas.meteo.pression = bmp.readPressure();
  datas.geographie.altitude = bmpreadAltitude(initialPressure);
}
int8_t setupBMP(){
  //bmp=(struct Adafruit_BMP085)calloc(1,sizeof(struct Adafruit_BMP085));
  if (!bmp.begin()) {
    return -1;
  }
  else {
    initialPressure = bmp.readPressure();
    return 1;
  }
}
