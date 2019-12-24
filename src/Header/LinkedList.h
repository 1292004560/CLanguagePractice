#ifndef PRACTISE_LINKEDLIST_H
#define PRACTISE_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>
struct Student{
    int number;//编号
    float score;//成绩
    struct Student *pointerNext;//存储下一个节点的地址
};
typedef struct Student ST;//简写结构体声明

void add(ST **pointerHead,int number, float score);//传入头节点的地址，然后插入节点

void showAll(ST *head);//传递头节点，显示所有数据

void * freeAll(ST *head);

ST * reverse(ST * head);//实现逆转

int getSize(ST * head);

ST * contain(ST *head,int number);

void change(ST *head,int oldNumber,int newNumber);

ST * addFirst(ST * head,int number,int newNumber, float score);//在第几个节点的后方插入一个新的节点

ST * addLast(ST * head,int number,int newNumber, float newScore);//在第几个节点的前方插入新的节点
#endif //PRACTISE_LINKEDLIST_H
