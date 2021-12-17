//
//  main.c
//  structure
//
//  Created by orsys on 16/12/2021.
//

#include <stdio.h>
struct S_gyro{
    float gx,gy,gz;
    float ix,iy,iz;
};
typedef struct S_gyro Gyro;
//def de la forme du contenu
struct S_meteo{
    float temp;
    uint32_t pression;
    uint8_t humidity;
};
struct S_Datas{
    struct S_meteo meteo;
    Gyro gyro;
};
void setTemperture(struct S_meteo *m){
    //(*m).temp=25.5;
    m->temp=27.0F;
    printf("in function -> %.2f;%6u;%2d\n",m->temp,m->pression,m->humidity);
}
void setGyro(struct S_Datas *d){
    
    d->gyro.gx=2.3F;
    d->gyro.gy=3.3F;
    d->gyro.gz=4.3F;
}
union U_S_Datas{
    struct S_Datas s;
    uint8_t b[sizeof(struct S_Datas)];
};

void viewUnionOfS_Data(struct S_Datas structData){
    union U_S_Datas usd;
    usd.s=structData;
    
    for (int i=0;i<sizeof(struct S_Datas);i++) {
        printf("%d;",usd.b[i]);
    }
    printf("\n");
}
int main(int argc, const char * argv[]) {
    //def de l'instance de la struct
    struct S_Datas datas;
    datas.meteo.temp=12.0F;
    datas.meteo.pression=102000ul;
    datas.meteo.humidity=37;
    setTemperture(&datas.meteo);
    setGyro(&datas);
    viewUnionOfS_Data(datas);
    //affichage du contenu de la structure
    printf("%.2f;%6u;%2d;%.3f;%.3f;%.3f\n",datas.meteo.temp,datas.meteo.pression,datas.meteo.humidity,datas.gyro.gx,datas.gyro.gy,datas.gyro.gz);
    printf("%lu",sizeof(float));
    return 0;
}

