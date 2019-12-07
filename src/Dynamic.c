#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
void main1(void){

    while(1){
        void * pointerVoid = malloc(1024 * 1024 * 10);
        //_sleep(2000);
        free(pointerVoid);
    }

    return;
}

void main(void){

    int number;
    scanf("%d",&number);
    int * integerPointer = (int *)malloc(sizeof(int)*number);
    for (int i = 0; i < number; ++i) {
        *(integerPointer+i) = i;
    }
    for (int i = 0; i < number; ++i) {
        printf("%2d",integerPointer[i]);
    }
    free(integerPointer);
    return;
}


