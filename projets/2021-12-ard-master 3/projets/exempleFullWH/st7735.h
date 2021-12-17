#ifndef __ST7735
#define __ST7735
#include "struct.h"
#include "pins.h"

#define ST_W 128
#define ST_H 160


#define POS_TIME_X 64
#define POS_TIME_Y 2

#define POS_PRESSURE_X 2
#define POS_PRESSURE_Y 32
void loopST7735(struct S_Datas datas);
void setupST7735();
#endif
