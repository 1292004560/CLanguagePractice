#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int add(int a, int b) {
    return a + b;
}

void main1(void) {


    printf("%p", add);

    int (*pointer)() = add;

    printf("\n%d", pointer(1, 2));

    return;
}

//函数返回一个地址
int * findMinElement(int array[], int n) {//对于数组而言函数参数没有副本机制,为了节约内存
    int *minElementAddress = NULL;//保存最小数的地址
    int minElement = array[0];
    minElementAddress = &array[0];
    for (int i = 1; i < n; ++i) {
        if (minElement > array[i]) {
            minElement = array[i];
            minElementAddress = &array[i];
        }
    }

    return minElementAddress;

}

void main2(void) {


    int array[10];
    time_t systemTime;

    srand((unsigned int) time(&systemTime));
    for (int i = 0; i < 10; ++i) {
        array[i] = rand() % 100;
        printf("%d\n", array[i]);
    }
    printf("================================");
    printf("\n\n%p,%d",findMinElement(array,10),*findMinElement(array,10));
    return;

}

void main3(void){

    char string[40];
    printf("%s",strcpy(string,"你好"));
    return;
}
char * copyString(char * destString,char *sourceString){

    char * lastString = NULL;
    if (destString == NULL || sourceString == NULL)
        return lastString;

    lastString = destString;//将首地址赋值给lastString变量

    while((*destString++ = *sourceString++) != '\0');

    return lastString;

}

void main4(void){

    char string[40] = {0};

    printf("%s",copyString(string,"你好"));

    return;
}

void main5(){

    int a = 5;//能放在赋值号左边赋值的值就是左值
    int *integerPointer = &a;//integerPointer是个左值

    int *const constPointer ;

//    constPointer = &a;//constPointer是一个指针常量，不可以被赋值

    void * pointerVoid;//void类型的指针可以传递地址
    double number = 10.0;
    double *doublePointer ;
    doublePointer = &number;

    pointerVoid = doublePointer;//void类型的指针可以传递地址

    //printf("%d",*pointerVoid);//void类型的指针，由于指向不明确，大小不确定，所以无法取出值
    printf("\n%f",*(double *)pointerVoid);
    //void类型的指针用于参数还有返回值，不明确指针类型的情况下传递地址
    //要把它用于某种类型的指针，需要强制转换

    return;
}

void main(void){

    int * pInt =NULL;
    //double * pDouble = 0x123;
   // pInt = pDouble;
    return;
}



