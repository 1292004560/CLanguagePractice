#include <stdio.h>
#include <stdlib.h>

//malloc，calloc都是分配内存，malloc根据大小，calloc根据元素大小还有个数
//malloc分配内存不会初始化，calloc会自动初始化为0

//realloc就是内存不够用的情况下，拓展内存
//如果原来的内存后部无人使用，就直接拓展
//有人使用就重新分配，并且先拷贝原来的内存的内容，然后回收原来的内存


void main1(void) {

    int number;
    scanf("%d", &number);
    printf("number = %d\n", number);

    int *pointerInt = (int *) calloc(number, sizeof(int));//第一个参数，多少个，第二个参数元素多大
    //calloc会自动将内存初始化为0，malloc不会初始化内存
    if (pointerInt == NULL) {
        printf("分配成功\n");
    } else {
        printf("分配成功\n");
        for (int i = 0; i < number; ++i) {
            pointerInt[i] = i;
            printf("%d\n", pointerInt[i]);
        }
    }

    free(pointerInt);


    return;
}

void main(void){

    int number,addNumber;
    scanf("%d%d",&number,&addNumber);
    printf("number = %d,addNumber = %d\n",number,addNumber);

    int * pointerInteger = (int *)malloc(sizeof(int)*number);

    int * pointerIntegerAdd = NULL;

    if (pointerInteger == NULL){
        printf("内存分配失败\n");
    } else{
        printf("分配成功\n");
        for (int i = 0; i < number; ++i) {
            pointerInteger[i] = i;
        }

        printf("=================================\n");
        //重新分配内存，如果可以拓展就拓展，否则就重新分配
        //拓展就是原来地址后面增加内存
        //不够的情况下，就回收原来的内存，并在回收之前分配一片内存，将原来的数据拷贝到新的内存之中
        pointerIntegerAdd =(int *)realloc((void *)pointerInteger, sizeof(int)*(addNumber+number));
        for (int i = number; i < addNumber + number; ++i) {
            pointerIntegerAdd[i] = i;
            printf("%d\n",pointerIntegerAdd[i]);
        }

    }

    printf("===========================\n");
    for (int i = 0; i < number + addNumber; ++i) {
        printf("%d\n",pointerIntegerAdd[i]);
    }

    free(pointerIntegerAdd);
    return;
}
