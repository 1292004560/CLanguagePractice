#include <stdlib.h>
#include <stdio.h>
#include <memory.h>//�ڴ��������
#include <string.h>
#include <math.h>
#include <locale.h>//���ñ��ػ�

void * myMemset(void * pointer ,int number,int length){
    char * px = (char *)pointer;//����һ���ַ��������տ�ָ��ĵ�ַ
    if(pointer == NULL){
        return px;// ���ؿ�ָ��
    }
    while(length>0){
        *px = (char)number;
        px++;
        length --;
    }
    return pointer;
}

int toInteger(char * string){
    int number = strlen(string)-1;//�����ַ����ĳ���
    int toInteger = 0;// ���ص��ַ���
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

    wchar_t wchar =L'��';
    printf("%d\n", sizeof(wchar));
    setlocale(LC_ALL,"chs");
    wprintf(L"%wc",wchar);
}

void main6(void){

    char *string1 = "AAAA";
    char * string2 = "aaaa";

    int number = memicmp(string1,string2,4);
    if(number == 0){
        printf("���Դ�Сд�����");
    }else{
        printf("����");
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
    //�ӵ�ַstring��ʼǰ��30���ַ�
    //���ڷ��ص�ַ
    //���򷵻ؿ�
    printf("%c\n",*pointer);
}


void main4(void){

    char string[30] = "zhoushuiping8848";
    char string1[30] = "hello.c";
    _memccpy(string,string1,'i',7);//����i����ֹ
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
    //��һ���������ڴ���׵�ַ���ڶ���������Ҫ���õ��ֽ�
    // ������������Ҫ���õĸ���
    printf("%s",string);
    memset(string,0,100);
    printf("%s\n",string);
    return;

}
