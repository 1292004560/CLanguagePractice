#include <stdlib.h>
#include <stdio.h>
#include <memory.h>//内存操作函数
#include <string.h>
#include <math.h>
#include <locale.h>//设置本地化

void * myMemset(void * pointer ,int number,int length){
    char * px = (char *)pointer;//创建一个字符串，接收空指针的地址
    if(pointer == NULL){
        return px;// 返回空指针
    }
    while(length>0){
        *px = (char)number;
        px++;
        length --;
    }
    return pointer;
}

int toInteger(char * string){
    int number = strlen(string)-1;//计算字符串的长度
    int toInteger = 0;// 返回的字符串
    while(*string!='\0'){
        if ((*string)<'0'||(*string)>'9')
            return -1;
        toInteger += (*string-'0')*(int)pow(10,number);
        string++;
        number--;
    }
    return toInteger;
}


void main(void){

    wchar_t wchar =L'我';
    printf("%d\n", sizeof(wchar));
    setlocale(LC_ALL,"chs");
    wprintf(L"%wc",wchar);
}

void main6(void){

    char *string1 = "AAAA";
    char * string2 = "aaaa";

    int number = memicmp(string1,string2,4);
    if(number == 0){
        printf("忽略大小写，相等");
    }else{
        printf("不等");
    }
    int i = '9' - '0';
    printf("%d\n",i);
    printf("%d\n",(int)pow(5,2));
    printf("%d\n",toInteger("1234"));
    return;
}

void main5(void){
    char string[30] = "hello zhoushuiping";
    char c = 'o';
    char * pointer = memchr(string,'o',30);
    //从地址string开始前进30个字符
    //存在返回地址
    //否则返回空
    printf("%c\n",*pointer);
}


void main4(void){

    char string[30] = "zhoushuiping8848";
    char string1[30] = "hello.c";
    _memccpy(string,string1,'i',7);//遇到i就终止
    printf("%s\n",string);
    return;
}


void main2(void){

    char string[30] = "zhoushuiping8848";
    char string1[30] = "hello.c";
    memcpy(string,string1,5);
    printf("%s\n",string);
    return;
}

void main1(void){

    char string[100] = "hello zhoushuiping";
    memset(string,'A',100);
    //第一个参数是内存的首地址，第二个参数是要设置的字节
    // 第三个参数是要设置的个数
    printf("%s",string);
    memset(string,0,100);
    printf("%s\n",string);
    return;

}
