
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
        printf("打开失败");
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
        printf("打开失败");
    } else{
        int result = fwrite(students, sizeof(Student),2,pointerFile);
        if (result == 2){
            printf("写入成功");

        }


    }
    fclose(pointerFile);
    return;
}

void main3(void){

    int array[100];
    FILE * pointerFile = fopen("c:\\a.txt","rb");//二进制模式打开文件
    if (pointerFile == NULL){
        printf("文件打开失败");
    } else{
        int result = fread(array, sizeof(int),100,pointerFile);
        if (result == 100){
            printf("读取成功\n");
            for (int i = 0; i < 100; ++i) {
                printf("array[%d] = %d\n",i,array[i]);
            }
        } else{
            printf("读取失败");
        }
    }

    return;
}

void mainw(void){

    int array[100];//数组是连续排列的，是一段连续的内存
    for (int i = 0; i <100 ; ++i) {
        array[i] = i;//初始化数组
    }
    FILE * pointerFile = fopen("c:\\a.txt","wb");//二进制写入的方式打开这个文件
    if (pointerFile == NULL){
        printf("文件打开失败");
    } else{
        int result = fwrite(array, sizeof(int),100,pointerFile);//将内存写入文件
        //写成多少个会返回数量
        //要写入内存的首地址
        //一个元素有多大
        //写多少个元素
        //写到那个文件
        if (result == 100){
            printf("写入成功");
        } else{
            printf("写入失败");
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
        printf("文件打开失败");
    } else{
        printf("文件打开成功\n");
        while (!feof(pointerFile)){
            char  ch = fgetc(pointerFile);

        }
//        int result = fputc('a',pointerFile);//写入不会报错，写入会失败
//        printf("%d\n",result);
//        if (result == -1){
//            printf("写入失败");
//        } else{
//            printf("写入成功");
//        }
    }
    fclose(pointerFile);
    return;
}
