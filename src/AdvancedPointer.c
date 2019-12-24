
#include <stdio.h>
#include <stdlib.h>

int add(int a,int b){
    return a+b;
}
int subtract(int a,int b){
    return a-b;
}

int divide(int a,int b){
    return a/b;
}

int multiply(int a,int b){
    return a*b;
}

void main(void){


}

void main4(void){

    int (*pointer[4])(int a,int b);
    int X = 100;
    int Y = 20;
    pointer[0] = add;
    pointer[1] = subtract;
    pointer[2] = divide;
    pointer[3] = multiply;
    for (int i = 0; i < 4; ++i) {
        printf("%d\n",pointer[i](X,Y));
    }

    return;
}

void main3(void){

    char * pointerArray[5] = {"calc","notepad","tasklist","mspaint","write"};
    printf("%d\n", sizeof(pointerArray));
    for (int i = 0; i < 5; ++i) {
        printf("%s,%c\n",pointerArray[i],*pointerArray[i]);
    }

    return;
}


void main2(void) {

    const int array[5] = {12000, 200, 300, 900, 400};//只读数组
    int *pointerArray[5] = {&array[0], &array[1], &array[2], &array[3], &array[4]};
    for (int i = 0; i < 5; ++i) {
        printf("%d,%d\n", *pointerArray[i],*(*pointerArray+i));
    }
    printf("指针循环方式\n");
    for (int **pointer = pointerArray; pointer < pointerArray + 5; pointer++) {
        printf("%d\n", **pointer);
    }
    return;
}

void main1(void) {

    int array[2][3][4];
    int number = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 4; ++k) {
                array[i][j][k] = number;
                number++;
                printf("%7d", array[i][j][k]);
            }
        }
    }
    return;
}

