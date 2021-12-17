#ifndef __ST7735
#define __ST7735
#include "struct.h"
  #include <Adafruit_ST77xx.h>
  #include <Adafruit_ST7789.h>
  #include <Adafruit_ST7735.h>
    #define TFT_CS        7
  #define TFT_RST        8 // Or set to -1 and connect to Arduino RESET pin
  #define TFT_DC         9
  #define POS_TIME_X 44
  #define POS_TIME_Y 2
  
  #define POS_PRESS_X 44
  #define POS_PRESS_Y 10
void initST();
void loopST( S_Datas);
#endif
