#include "../Header/LinkedListStack.h"

Stack *initStack(Stack *pointerHead) {
    return NULL;

}

Stack *push(Stack *pointerHead, int number, DataType data) {
    Stack *pointerNewNode = (Stack *) malloc(sizeof(Stack));//分配内存
    pointerNewNode->number = number;
    pointerNewNode->data = data;
    pointerNewNode->pointerNext = NULL;
    if (pointerHead == NULL) {
        pointerHead = pointerNewNode;
        return pointerHead;
    } else {
        Stack * auxiliaryNode = pointerHead;
        while (auxiliaryNode->pointerNext != NULL) {
            auxiliaryNode = auxiliaryNode->pointerNext;
        }
        auxiliaryNode->pointerNext = pointerNewNode;
        return pointerHead;
    }
}

void printAllNode(Stack * pointerHead){
    if (pointerHead == NULL){
        return;
    } else{
        printf("%d,%d\n",pointerHead->number,pointerHead->data);
        printAllNode(pointerHead->pointerNext);
    }

}

Stack * pop(Stack * pointerHead,Stack * pointerOutData){
    if (pointerHead == NULL){
        return NULL;
    } else if(pointerHead->pointerNext == NULL){
        pointerOutData->data = pointerHead->data;
        pointerOutData ->number = pointerHead->number;
        free(pointerHead);
        pointerHead = NULL;//设置节点为空
        return NULL;
    } else{
        Stack * auxiliaryPointer = pointerHead;
        Stack * auxiliaryPointerOne = auxiliaryPointer->pointerNext;
        while (auxiliaryPointerOne->pointerNext != NULL){
            auxiliaryPointer = auxiliaryPointer->pointerNext;
            auxiliaryPointerOne = auxiliaryPointer->pointerNext;
        }
        pointerOutData->number = auxiliaryPointerOne->number;
        pointerOutData->data = auxiliaryPointerOne->data;
        free(auxiliaryPointerOne);//释放内存
        auxiliaryPointer->pointerNext = NULL;
        return pointerHead;

    }
}

Stack * freeAll(Stack * pointerHead){
    if (pointerHead == NULL){
        return NULL;
    } else{
        Stack * auxiliaryPointerOne;
        Stack * auxiliaryPointerTwo;
        auxiliaryPointerOne = auxiliaryPointerTwo = NULL;//初始化结点
        auxiliaryPointerOne = pointerHead;
        while (auxiliaryPointerOne->pointerNext != NULL){
            auxiliaryPointerTwo = auxiliaryPointerOne->pointerNext;
            auxiliaryPointerOne->pointerNext = auxiliaryPointerTwo->pointerNext;
            free(auxiliaryPointerTwo);
        }
        free(pointerHead);
        return NULL;

    }
}



