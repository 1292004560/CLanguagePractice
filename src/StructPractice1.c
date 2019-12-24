
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ours {

    int number;
    char string[100];
}Ours;


void main(void){

    Ours *pointer = (Ours *)malloc(sizeof(Ours)*10);

//    pointer->number = 12;
//    sprintf(pointer->string,"zhoushuiping");
//    sprintf(pointer->string,"ssssss");
//    printf("%d,%s\n",pointer->number,pointer->string);
//    getchar();

    for (int i = 0; i < 10; ++i) {
        //写数据
        sprintf((pointer+i)->string,"ihao%d",i);
        (pointer+i)->number = i;
    }
    for (int i = 0; i < 10; ++i) {
        printf("%s,%d\n",(pointer+i)->string,(pointer+i)->number);
    }
    return;
}

void main1(void) {

    struct Ours ours = {12,"zhoushuiping"};

    // printf("%d,%s\n",ours.number,ours.string);

    struct Ours *p;
    printf("%d\n", sizeof(p));


    p = &ours;

    printf("%d,%s\n",p->number,p->string);

    struct Ours ours1[3] = {{12,"sss"},{12,"rrr"},{34,"dddsd"}};

    for(struct Ours * pointer = ours1;pointer<ours1+3;pointer++){
        printf("%s,%d\n",pointer->string,pointer->number);
    }

    return;
}

