#include "../Header/LinkedQueue.h"
Queue * initQueue(Queue * queuePointer){
    return NULL;
}

Queue * enqueue(Queue * queuePointer,int number,int priority){

    Queue * pointerNewNode = (Queue *)malloc(sizeof(Queue));
    pointerNewNode->data = number;
    pointerNewNode->priority = priority;
    pointerNewNode->pointerNext = NULL;

    if (queuePointer == NULL){
        queuePointer = pointerNewNode;
        return queuePointer;
    } else{
        Queue * auxiliaryPointer = queuePointer;
        while(auxiliaryPointer->pointerNext != NULL){
            auxiliaryPointer = auxiliaryPointer->pointerNext;
        }
        //确定要插入的位置
        auxiliaryPointer->pointerNext = pointerNewNode;
        return queuePointer;//返回头节点
    }



}

Queue * dequeue(Queue * queuePointer,Queue * pointerOutElement){

    if (queuePointer == NULL){
        return NULL;
    } else{
        pointerOutElement->data = queuePointer->data;
        pointerOutElement->priority = queuePointer->priority;
        Queue * pointerTemporary = queuePointer;//临时中间变量，保存头节点的地址
        queuePointer = queuePointer->pointerNext;
        free(pointerTemporary);
        return queuePointer;//返回头节点
    }
}

void sort(Queue * queuePointer){//优先级排队

    if (queuePointer == NULL || queuePointer->pointerNext == NULL)
        return;


    for (Queue * pointerOne = queuePointer; pointerOne != NULL ; pointerOne = pointerOne->pointerNext) {

        for (Queue* pointerTwo = queuePointer;  pointerTwo != NULL ; pointerTwo =  pointerTwo->pointerNext) {

            if (pointerOne->priority > pointerTwo->priority){

                Queue temporaryQueue;
                temporaryQueue.data = pointerOne->data;
                pointerOne->data = pointerTwo->data;
                pointerTwo->data = temporaryQueue.data;


                temporaryQueue.priority = pointerOne->priority;
                pointerOne->priority = pointerTwo->priority;
                pointerTwo ->priority = temporaryQueue.priority;
            }


        }

    }



}

void printQueue(Queue * queuePointer){

    if (queuePointer == NULL){
        printf("->NULL");
        return;
    } else{
        printf("(%d,%d,%p,%p)->",queuePointer->data,queuePointer->priority,queuePointer,queuePointer->pointerNext);
        printQueue(queuePointer->pointerNext);
    }
}
