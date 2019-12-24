
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct NameInformation{

    char name[30];
    char phone[20];
    int number;
};

struct dangdang{

    char email[30];
    char name[30];
    char address[30];
    int bigNumber;
    char telephone[20];
    char phone[20];
    double RMB;
}d1,d2,d3;


struct {//无名结构体
    char name[30];
    char phone[50];
    int number;
}M1,M2,M3;


void main4(void){

    struct dangdang structdangdang = {"2432424@qq.com","名","大冶市",142,"234","12345",34.9};


    printf("%s\n",structdangdang.email);


    return;
}

void main2(void){

    d1.bigNumber = 199;

    return ;
}



void main1(void){

    struct NameInformation information;
    information.number = 100;
    //information.name = {"周水平"};//字符串不能等号赋值
    sprintf(information.name,"zhoushuiping");
    printf("%s\n",information.name);
    strcpy(information.phone,"123456778");
    printf("%s\n",information.phone);
    return;
}

