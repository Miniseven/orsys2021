#ifndef _STRUCT_H_
#define _STRUCT_H_

//def. des strucutres commune à toute mon app
struct S_meteo{
    float temp;
    unsigned long pression;
    unsigned short humidity;
};

struct S_Geographie{
  unsigned int altitude;
}

struct S_Datas{
    struct S_Meteo meteo;
    struct S_Geographie geographie;
    char ds_time[20];
};

// instance communes de datas pour tous les fichiers inclunats struct.h

struct S_Datas datas;

#endif
