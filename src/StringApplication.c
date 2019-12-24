#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void main(void){

    char string[30] = "dflaksdjgsaldgjlkas;gj;lsakg";
    char * pointerString = strchr(string,'a');//第一个字符串不一定要求是字符串的首地址 可以string+3
    if (pointerString == NULL){
        printf("没有找到\n");
    } else{
        printf("找到了\n");
    }
    return;
}

void main00(void){

    char * pointerString = "abcdefg" ,*pointerStringToUpper;



    printf("%s\n",strupr(pointerString));

}


void main15(void){

    char stringOne[100] = "apppatch";
    char stringTwo[100] = "Apppdff";
    strupr(stringOne);
    strupr(stringTwo);
    printf("%s\n%s\n",stringOne,stringTwo);


    return;
}


void main16(void){

    char * pointerString = "abcdefg";

    printf("%s\n",strupr(pointerString));
    return;
}

void main14(void){

    char stringOne[100] = "ADFSA";
    char stringTwo[100] = "admin";
    int number = strcmp(stringOne,stringTwo);
    printf("%d\n",number);
    return;
}

void main13(void){

    char stringOne[100] = "zhou";
    char stringTwo[100] = "zhou";
    int number = strcmp(stringOne,stringTwo);
    printf("%d\n",number);
    if (number == 0){
        printf("相等\n");
    } else{
        printf("不等");
    }
    return ;
}


void main12(void){
    char stringOne[100] = {"my name is zhoushuiping"};
    char stringTwo[100] = {"zhou"};
    char * pointerString = strstr(stringOne,stringTwo);
    if (pointerString == NULL){
        printf("没有找到");
    } else{
        printf("找到了");
    }
    return ;
}

void main11(void){

    char string[100] = "我有100元";
    int number;
    sscanf(string,"我有%d元",&number);
    printf("%d\n",number);
    return;
}


void main10(void){
    char string[100] = "for /l %i in (1,1,5) do calc";

    char * pointerString = "nihao";//pointerString指向的一个常量不能通过  *pointerString来修改值

    system(string);

}

//函数的副本机制，只有数组例外，数组拷贝非常耗费时间和空间
void changeCharacter(char string[]){//数组传递过来的实际上是指针的地址
    printf("changeCharacter = %d\n", sizeof(string));//打印指针的大小4个字节
    *string = 'A';
    *(string+1) = 'B';
}

void main9(void){

    char string[100];
    scanf("%s",string);
    changeCharacter(string);
    printf("%s",string);

    return ;
}


void main8(void){
   // char stringArray[100] = "tasklist";// 创建的时候可以用字符串初始化字符数组
   // char stringArray[100];
   // stringArray[100] = "tasklist";//stringArray[100] 代表101个元素
    //printf("%s\n",stringArray);

    char * pointerString = "tasklist";//pointer存储了字符串的首地址
    pointerString = "tasklist";//pointerString是一个变量

};



void main7(void){

    //char * stringPointer = NULL;//0x00000 ,用指针初始化，必须让指针存储一片可以读写的内存地址
    char stringArray[100];
    char * stringPointer = stringArray;//指针存储了一片内存的首地址
    scanf("%s",stringPointer);
    printf("%s",stringPointer);

    return ;
}


void main6(void){

    char stringArray[100] = {0};
    scanf("%s",stringArray);
    printf("%s",stringArray);
    return;
}


void main5(void){

    time_t systemTime;
    srand((unsigned int)time(&systemTime));//去时间的随机数种子
    int number = rand() % 10;

    printf("%d\n",number);
    char stringArray[10][10] = {{"calc"},{"notepad"},{"write"},{"tasklist"},{"ipconfig"},{"color 4f"},{"mspaint"},{"mstsc"},{"msconfig"}};
    system(stringArray[number]);
}


void main4(void){

    char stringArray[100] = {"color 4f"};
    //system(stringArray);

    return;
}


void main3(void){


    char *stringPointer = "title China is great";
    while (*stringPointer){
        putchar(*stringPointer);
        stringPointer++;//指针向前移动
    }//stringPointer指向为空

    return;
}


void main1(void){

    //char  string[30] = "calc";
    //system(string);

    char * stringPinter = "I am a boy";
    //system(stringPinter);

    printf("\n%d", sizeof(stringPinter));
    printf("\n%d", sizeof("I am a boy"));
   // *stringPinter = 'A';//对常量字符串的一个字符赋值，不合法

    printf("\n %c",*stringPinter);

    return;
}

void main2(void){

    char stringArray[10] = "write";//数组stringArray是一个变量


    return ;

}

