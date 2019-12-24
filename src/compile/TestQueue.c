
#include "../Header/LinkedQueue.h"
#pragma comment(lib,"user32.lib")
void main(void){

    Queue  * queuePointer = NULL;
    queuePointer = initQueue(queuePointer);


    queuePointer = enqueue(queuePointer,1,1);
    queuePointer = enqueue(queuePointer,2,1);
    queuePointer = enqueue(queuePointer,3,1);

    queuePointer = enqueue(queuePointer,4,1);

    queuePointer = enqueue(queuePointer,4,1);

    printQueue(queuePointer);

    while (queuePointer!=NULL){
        Queue * pointerTemporary = (Queue*)malloc(sizeof(Queue));
        queuePointer = dequeue(queuePointer,pointerTemporary);

        printf("\n ------------\n");
        printQueue(queuePointer);

    }
    return;
}

