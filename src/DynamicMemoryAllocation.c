#include <stdio.h>
#include <stdlib.h>

//malloc��calloc���Ƿ����ڴ棬malloc���ݴ�С��calloc����Ԫ�ش�С���и���
//malloc�����ڴ治���ʼ����calloc���Զ���ʼ��Ϊ0

//realloc�����ڴ治���õ�����£���չ�ڴ�
//���ԭ�����ڴ������ʹ�ã���ֱ����չ
//����ʹ�þ����·��䣬�����ȿ���ԭ�����ڴ�����ݣ�Ȼ�����ԭ�����ڴ�


void main1(void) {

    int number;
    scanf("%d", &number);
    printf("number = %d\n", number);

    int *pointerInt = (int *) calloc(number, sizeof(int));//��һ�����������ٸ����ڶ�������Ԫ�ض��
    //calloc���Զ����ڴ��ʼ��Ϊ0��malloc�����ʼ���ڴ�
    if (pointerInt == NULL) {
        printf("����ɹ�\n");
    } else {
        printf("����ɹ�\n");
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
        printf("�ڴ����ʧ��\n");
    } else{
        printf("����ɹ�\n");
        for (int i = 0; i < number; ++i) {
            pointerInteger[i] = i;
        }

        printf("=================================\n");
        //���·����ڴ棬���������չ����չ����������·���
        //��չ����ԭ����ַ���������ڴ�
        //����������£��ͻ���ԭ�����ڴ棬���ڻ���֮ǰ����һƬ�ڴ棬��ԭ�������ݿ������µ��ڴ�֮��
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
