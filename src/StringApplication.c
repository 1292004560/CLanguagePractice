#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void main(void){

    char string[30] = "dflaksdjgsaldgjlkas;gj;lsakg";
    char * pointerString = strchr(string,'a');//��һ���ַ�����һ��Ҫ�����ַ������׵�ַ ����string+3
    if (pointerString == NULL){
        printf("û���ҵ�\n");
    } else{
        printf("�ҵ���\n");
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
        printf("���\n");
    } else{
        printf("����");
    }
    return ;
}


void main12(void){
    char stringOne[100] = {"my name is zhoushuiping"};
    char stringTwo[100] = {"zhou"};
    char * pointerString = strstr(stringOne,stringTwo);
    if (pointerString == NULL){
        printf("û���ҵ�");
    } else{
        printf("�ҵ���");
    }
    return ;
}

void main11(void){

    char string[100] = "����100Ԫ";
    int number;
    sscanf(string,"����%dԪ",&number);
    printf("%d\n",number);
    return;
}


void main10(void){
    char string[100] = "for /l %i in (1,1,5) do calc";

    char * pointerString = "nihao";//pointerStringָ���һ����������ͨ��  *pointerString���޸�ֵ

    system(string);

}

//�����ĸ������ƣ�ֻ���������⣬���鿽���ǳ��ķ�ʱ��Ϳռ�
void changeCharacter(char string[]){//���鴫�ݹ�����ʵ������ָ��ĵ�ַ
    printf("changeCharacter = %d\n", sizeof(string));//��ӡָ��Ĵ�С4���ֽ�
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
   // char stringArray[100] = "tasklist";// ������ʱ��������ַ�����ʼ���ַ�����
   // char stringArray[100];
   // stringArray[100] = "tasklist";//stringArray[100] ����101��Ԫ��
    //printf("%s\n",stringArray);

    char * pointerString = "tasklist";//pointer�洢���ַ������׵�ַ
    pointerString = "tasklist";//pointerString��һ������

};



void main7(void){

    //char * stringPointer = NULL;//0x00000 ,��ָ���ʼ����������ָ��洢һƬ���Զ�д���ڴ��ַ
    char stringArray[100];
    char * stringPointer = stringArray;//ָ��洢��һƬ�ڴ���׵�ַ
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
    srand((unsigned int)time(&systemTime));//ȥʱ������������
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
        stringPointer++;//ָ����ǰ�ƶ�
    }//stringPointerָ��Ϊ��

    return;
}


void main1(void){

    //char  string[30] = "calc";
    //system(string);

    char * stringPinter = "I am a boy";
    //system(stringPinter);

    printf("\n%d", sizeof(stringPinter));
    printf("\n%d", sizeof("I am a boy"));
   // *stringPinter = 'A';//�Գ����ַ�����һ���ַ���ֵ�����Ϸ�

    printf("\n %c",*stringPinter);

    return;
}

void main2(void){

    char stringArray[10] = "write";//����stringArray��һ������


    return ;

}

