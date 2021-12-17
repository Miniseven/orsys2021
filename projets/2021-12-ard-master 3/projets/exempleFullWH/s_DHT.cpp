#include "s_DHT.h"

DHT dht(DHTPIN, DHTTYPE);

void setupDHT(){
    dht.begin();
}

void loopDHT(){
    s.meteo.rhumidity= dht.readHumidity();
}
