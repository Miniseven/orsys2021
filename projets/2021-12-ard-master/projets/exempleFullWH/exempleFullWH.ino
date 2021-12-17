#include "struct.h"
#include "st7735.h"
#include "s_ds18b20.h"
#include "s_DHT.h"
#include "s_sd.h"

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  setupDS1307(); 
  setupBMP(); 
  setupDHT();
  setupST7735();
  setupDS18();
setupSD();
}

void loop() {
  // put your main code here, to run repeatedly:
  loopDS1307();
  loopDHT();
  loopBMP();
  loopDS18();
  loopST7735(s);
  loopSD();
  delay(900);
}
