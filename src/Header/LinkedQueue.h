
#ifndef PRACTISE_LINKEDQUEUE_H
#define PRACTISE_LINKEDQUEUE_H

#include <stdio.h>
#include <stdlib.h>

struct queue{
    int data;//数据
    int priority;//优先级
    struct queue * pointerNext;//存储下一个节点的地址
};

typedef struct queue Queue;

Queue * initQueue(Queue * queuePointer);

Queue * enqueue(Queue * queuePointer,int number,int priority);

Queue * dequeue(Queue * queuePointer,Queue * pointerOutElement);

Queue * freeAll(Queue  * queuePinter);

void sort(Queue * queuePointer);

void printQueue(Queue * queuePointer);

#endif //PRACTISE_LINKEDQUEUE_H
