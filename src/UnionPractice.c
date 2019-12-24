#include <stdio.h>
#include <stdlib.h>

struct info{
    int price;  //8
   // char string[20];
    double a;      //8
    char string[20]; //24
};

void main(void){

    printf("%d\n", sizeof(double));
    //printf("%llu\n", sizeof(union info));
    //union info unioninfo;
   // unioninfo.a = 1;
    printf("%d\n", sizeof(struct info));
    return;
}

