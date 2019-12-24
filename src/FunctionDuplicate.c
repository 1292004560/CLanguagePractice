#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * getMemoryAddress(){

    char string[100] = "1234567";//栈上的内存，系统自动分配和回收
    char * pointer = string;//存储数组的首地址
    return pointer;
}
char * getDynamicMemoryAddress(){
    char * pointer = (char *)malloc(100);

    return pointer;
}


long go(int n){
    if (n == 1 || n==2)
        return n;
    return go(n -1)+go(n-2);
}

void main(void){

    int number = 0;
    while (1){
        system("start notepad");//异步
        number ++;
        if (number >10){
            exit(0);
        }
    }

    return;
}

void main3(void){

    printf("%d\n",go(50));
    return;
}


void main2(void){


    char * pointer = getDynamicMemoryAddress();
    if (pointer != NULL){
        strcpy(pointer,"hello world");
    }
    free(pointer);
    return;
}

void main1(void){

    char * pointerString = NULL;//定义一个空指针
    pointerString = getMemoryAddress();
    if (pointerString != NULL)
        strcpy(pointerString,"hello world");

    printf("%s\n",pointerString);
    getchar();

    return;
}
