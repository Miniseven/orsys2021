//
//  main.c
//  structure
//
//  Created by orsys on 16/12/2021.
//

#include <stdio.h>

struct S_{
    float temp;
    long pression;
    float humidity;
}S_meteo;

int main(int argc, const char * argv[]) {
    struct S_ meteo;
    meteo.temp=23.4F;
    
    return 0;
}
