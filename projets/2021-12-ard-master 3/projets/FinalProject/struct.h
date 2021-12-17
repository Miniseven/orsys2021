#ifndef _STRUCT_H_
#define _STRUCT_H_
//def. des structures communes a toute mon app
struct S_Meteo{
    float temp;
    unsigned long pression;
    unsigned short humidity;
};
struct S_Geographie{
    unsigned int altitude;
};
struct S_Datas {
  struct S_Meteo meteo;
  struct S_Geographie geographie;
  char str_time[20];
};
//une instance commune de dats pour tous les fichiers incluants struct.h
struct S_Datas datas;
#endif
