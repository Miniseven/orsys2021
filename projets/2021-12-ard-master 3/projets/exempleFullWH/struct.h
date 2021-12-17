#if !defined(__STRUCT)
#define __STRUCT
#include <TimeLib.h>  
typedef struct S_Meteo{
  uint32_t pressure;
  float temp;
  float rhumidity;
}smeteo;
typedef struct S_Geo{
  int16_t alt;
}sgeo;
typedef struct S_Datas{
  S_Meteo meteo;
  S_Geo geo;
  tmElements_t tm;
}sdatas;
static S_Datas s;
#endif
