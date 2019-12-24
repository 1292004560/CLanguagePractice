#include <stdlib.h>
#include <stdio.h>
#define N 100 //定义队列最大多少个
#define DataType char //定义数据类型
//结构体队列
struct Queue {
    DataType data[N];
    int front;  //存放删除的一端
    int rear;//允许插入的一端
};
typedef struct Queue Queue;


void initQueue(Queue * queuePointer);//初始化队列
int isEmpty(Queue * queuePointer);//判断队列是否为空
DataType getFirstElement(Queue * queuePointer);

void enqueue(Queue * queuePointer,DataType data);
DataType dequeue(Queue * queuePointer);
void showAllElements(Queue * queuePointer);

void initQueue(Queue * queuePointer){
    queuePointer->front = queuePointer->rear =0;
}
int isEmpty(Queue * queuePointer){
    if (queuePointer->rear == queuePointer->front){
        return 1;
    } else{
        return 0;
    }
}

DataType getFirstElement(Queue * queuePointer){

    if(isEmpty(queuePointer)){
        return -1;
    }
    return queuePointer->data[queuePointer->front];
}

void enqueue(Queue * queuePointer , DataType data){
    if(queuePointer ->rear == N){
        return;
    }
    queuePointer->data[queuePointer->rear] = data;
    queuePointer->rear++;
}

void showAllElements(Queue * queuePointer){
    if (queuePointer->front == queuePointer->rear){
        return;
    } else{
        for (int i = queuePointer->front; i < queuePointer->rear; ++i) {
            printf("%4c",queuePointer->data[i]);
        }
    }
}

DataType dequeue(Queue * queuePointer ){
    if(queuePointer->front == queuePointer->rear){
        return  -1;
    }
    queuePointer->front++;
    return queuePointer->data[queuePointer->front-1];
}




int main(void){

    char * string = "qwwvdfsv";
    Queue  queuePointer ;
    initQueue(&queuePointer);
    char * pointerString = string;
    while (*pointerString != 0){
        enqueue(&queuePointer,*pointerString);
        showAllElements(&queuePointer);
        printf("\n");
        pointerString++;
    }
    return 0;

}