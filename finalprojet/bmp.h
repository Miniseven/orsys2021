#ifndef _BMP_H_
#define _BMP_H_
// import structures communes à l'app
#include "struct.h"

// import des librairies pour le composant bmp 180/185
#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>


// definition des prototypes de fonctions pour accès des fichierrs inlant le C
void loopBMP();
void setupBMP();

#endif
