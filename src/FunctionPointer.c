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

//��������һ����ַ
int * findMinElement(int array[], int n) {//����������Ժ�������û�и�������,Ϊ�˽�Լ�ڴ�
    int *minElementAddress = NULL;//������С���ĵ�ַ
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
    printf("%s",strcpy(string,"���"));
    return;
}
char * copyString(char * destString,char *sourceString){

    char * lastString = NULL;
    if (destString == NULL || sourceString == NULL)
        return lastString;

    lastString = destString;//���׵�ַ��ֵ��lastString����

    while((*destString++ = *sourceString++) != '\0');

    return lastString;

}

void main4(void){

    char string[40] = {0};

    printf("%s",copyString(string,"���"));

    return;
}

void main5(){

    int a = 5;//�ܷ��ڸ�ֵ����߸�ֵ��ֵ������ֵ
    int *integerPointer = &a;//integerPointer�Ǹ���ֵ

    int *const constPointer ;

//    constPointer = &a;//constPointer��һ��ָ�볣���������Ա���ֵ

    void * pointerVoid;//void���͵�ָ����Դ��ݵ�ַ
    double number = 10.0;
    double *doublePointer ;
    doublePointer = &number;

    pointerVoid = doublePointer;//void���͵�ָ����Դ��ݵ�ַ

    //printf("%d",*pointerVoid);//void���͵�ָ�룬����ָ����ȷ����С��ȷ���������޷�ȡ��ֵ
    printf("\n%f",*(double *)pointerVoid);
    //void���͵�ָ�����ڲ������з���ֵ������ȷָ�����͵�����´��ݵ�ַ
    //Ҫ��������ĳ�����͵�ָ�룬��Ҫǿ��ת��

    return;
}

void main(void){

    int * pInt =NULL;
    //double * pDouble = 0x123;
   // pInt = pDouble;
    return;
}



