//
//  main.c
//  structure
//
//  Created by orsys on 16/12/2021.
//

#include <stdio.h>
struct S_meteo{
    float temp;
    uint32_t pression;
    uint8_t humidity;
};

struct S_gyro{
    float gx;
    float gy;
    float gz;
    float ix;
    float iy;
    float iz;
};
typedef struct S_gyro Gyro;

struct S_Datas{
    struct S_meteo meteo;
    Gyro gyro;
};

union U_S_Datas{
    struct S_Datas s;
    uint8_t b[sizeof(struct S_Datas)];
    
};

void setTemperature(struct S_meteo *m){
    m->temp=27.0F;
    printf("in function -> %.2f;%6u;%2d\n",m->temp,m->pression,m->humidity);
}
void setGyro(struct S_Datas *d){
    d->gyro.gx=2.3F;
    d->gyro.gy=3.3F;
    d->gyro.gz=4.3F;
    
}

void viewUnionOfS_Datas(struct S_Datas structData){
    union U_S_Datas usd;
    usd.s=structData;
    
    for (int y=0;y<sizeof(struct S_Datas);y++) {
        printf("%d",usd.b[y]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    struct S_Datas datas;
    datas.meteo.temp=12.0F;
    datas.meteo.pression=102000ul;
    datas.meteo.humidity=37;
    setTemperature(&(datas.meteo));
    setGyro(&datas);
    viewUnionOfS_Datas(datas);
    printf("%.2f;%6u;%2d;%.3f;%.3f;%.3f\n",datas.meteo.temp,datas.meteo.pression,datas.meteo.humidity,datas.gyro.gx,datas.gyro.gy,datas.gyro.gz);
    return 0;
}
