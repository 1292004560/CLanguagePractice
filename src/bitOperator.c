#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

float main(void){

    short  number = -1;
    printf("%d\n",number);
    printf("%u\n",number);
    printf("%d,%d\n",INT_MAX,INT_MIN);
    printf("%d,%d\n",INT_MAX,INT_MIN);
    printf("%u,%u\n",UINT_MAX,0);
    return 0.0;
}

void main6(void){

    //printf不会进行类型转换
    printf("%d\n",(int)10.0);//printf不管是什么类型，按照%d，%f解析

    printf("%f\n",(float)10);
    return;
}

void main3(void){

    unsigned char ch = 73;//01001001
    return;
}

void main4(void){

    printf("%d\n",1^1);
    printf("%d\n",1^0);

    return;
}

void main2(void){


    unsigned  char ch1 = 3;//0000  0011
    unsigned char ch2 = 240;// 1111  0000
    unsigned char ch3 = 255; // 1111  1111
    printf("%d,%d\n",ch1&ch2,0&0);
    printf("%d\n",ch2&ch3);

    return;
}


void main1(void){

    unsigned char c = 15;//0000 1111

    unsigned char cc = ~c;//1111 0000

    unsigned  char ccc = ~cc;//取反的作用1变0，0变1
    printf("%d\n",ccc);
    printf("%d\n",cc);

    return;
}

