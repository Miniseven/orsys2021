#include "struct.h"
#include "st7735.h"
void setup() {
  // put your setup code here, to run once:
  initDatas();
  initST();
}

void loop() {
  // put your main code here, to run repeatedly:
  loopST(s);
  delay(900);
}
void initDatas(){
  s.meteo.pressure=101000;
  s.meteo.temp=40.54;
  s.meteo.rhumidity=60.0F;
  s.geo.alt=1000.0F;
  s.tm.Hour=12;
  s.tm.Minute=23;
}
