#include <stdlib.h>
#include <stdio.h>

struct info{
    int number;
    void * pointer;
};

void main(void){

    //动态模式
    struct info * pointerInfo;

    pointerInfo = (struct info *)malloc(sizeof(struct info));//分配内存
    pointerInfo->number = 125;
    pointerInfo->pointer = &pointerInfo->number;
    printf("%d,%p",pointerInfo->number,pointerInfo->pointer);


    return;
}
void main1(void){

    //静态模式
    struct info structInfo;
    structInfo.number = 123;//赋值为整数
    structInfo.pointer = &structInfo;
    printf("%d,%p",structInfo.number,structInfo.pointer);

    return;
}

