#include "struct.h"
void setup() {
  // put your setup code here, to run once:
  initDatas();
}

void loop() {
  // put your main code here, to run repeatedly:

}
void initDatas(){
  s.meteo.pressure=101000;
  s.meteo.temp=40.54;
  s.meteo.rhumidity=60.0F;
  s.geo.alt=1000.0F;
  s.tm.Hour=12;
  s.tm.Minute=23;
}
