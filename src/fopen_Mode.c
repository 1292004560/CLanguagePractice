
#include <stdio.h>
#include <stdlib.h>
#include <io.h>

typedef struct {
    char firstName[10];
    char lastName[10];
}Student;


void main(void){

    FILE * pointerFile = fopen("c:\\b.txt","rb");
    Student students[2];
    if (pointerFile == NULL ){
        printf("��ʧ��");
    } else{
        int result = fread(students, sizeof(Student),2,pointerFile);
        for (int i = 0; i < 2; ++i) {
            printf("firstName = %s,lastName = %s\n",students[i].firstName,(students+i)->lastName);
        }
    }
    fclose(pointerFile);
    return;
}

void main4(void){
    Student students[2] = {{"1,2","dsk"},{"23","dd"}};
    FILE * pointerFile = fopen("c:\\b.txt","wb");
    if (pointerFile == NULL){
        printf("��ʧ��");
    } else{
        int result = fwrite(students, sizeof(Student),2,pointerFile);
        if (result == 2){
            printf("д��ɹ�");

        }


    }
    fclose(pointerFile);
    return;
}

void main3(void){

    int array[100];
    FILE * pointerFile = fopen("c:\\a.txt","rb");//������ģʽ���ļ�
    if (pointerFile == NULL){
        printf("�ļ���ʧ��");
    } else{
        int result = fread(array, sizeof(int),100,pointerFile);
        if (result == 100){
            printf("��ȡ�ɹ�\n");
            for (int i = 0; i < 100; ++i) {
                printf("array[%d] = %d\n",i,array[i]);
            }
        } else{
            printf("��ȡʧ��");
        }
    }

    return;
}

void mainw(void){

    int array[100];//�������������еģ���һ���������ڴ�
    for (int i = 0; i <100 ; ++i) {
        array[i] = i;//��ʼ������
    }
    FILE * pointerFile = fopen("c:\\a.txt","wb");//������д��ķ�ʽ������ļ�
    if (pointerFile == NULL){
        printf("�ļ���ʧ��");
    } else{
        int result = fwrite(array, sizeof(int),100,pointerFile);//���ڴ�д���ļ�
        //д�ɶ��ٸ��᷵������
        //Ҫд���ڴ���׵�ַ
        //һ��Ԫ���ж��
        //д���ٸ�Ԫ��
        //д���Ǹ��ļ�
        if (result == 100){
            printf("д��ɹ�");
        } else{
            printf("д��ʧ��");
        }
    }
    fclose(pointerFile);

    return;
}


void main2(void){

    printf("%d\n",access("c:\\aa",0));

    return;
}


void main1(void){

    char path[40] = "c:\\a.txt";
    FILE * pointerFile = fopen(path,"a");
    if (pointerFile == NULL){
        printf("�ļ���ʧ��");
    } else{
        printf("�ļ��򿪳ɹ�\n");
        while (!feof(pointerFile)){
            char  ch = fgetc(pointerFile);

        }
//        int result = fputc('a',pointerFile);//д�벻�ᱨ��д���ʧ��
//        printf("%d\n",result);
//        if (result == -1){
//            printf("д��ʧ��");
//        } else{
//            printf("д��ɹ�");
//        }
    }
    fclose(pointerFile);
    return;
}
