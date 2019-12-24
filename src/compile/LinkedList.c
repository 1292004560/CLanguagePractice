#include "../Header/LinkedList.h"

void add(ST **pointerHead, int number, float score) {

    if (*pointerHead == NULL) {
        ST *newNode = (ST *) malloc(sizeof(ST));//分配内存
        newNode->number = number;//节点初始化
        newNode->score = score;
        newNode->pointerNext = NULL;
        *pointerHead = newNode;//让头节点指向这个节点
    } else {
        //链表不为空
        ST *temporaryPointer = *pointerHead;//指向头节点
        while (temporaryPointer->pointerNext != NULL) {
            temporaryPointer = temporaryPointer->pointerNext;
        }

        ST *newNode = (ST *) malloc(sizeof(ST));
        newNode->score = score;
        newNode->number = number;
        newNode->pointerNext = NULL;
        temporaryPointer->pointerNext = newNode;
    }
}

void showAll(ST *head) {

    while (head != NULL) {
        printf("number = %d,score = %f", head->number, head->score);
        head = head->pointerNext;
    }
}

void *freeAll(ST *head) {
    ST *pointerOneNode, *pointerTwoNode;//临时节点
    pointerOneNode = pointerTwoNode = NULL;//初始化指针
    pointerOneNode = head;
    while (pointerOneNode->pointerNext != NULL) {
        pointerOneNode->pointerNext = pointerTwoNode;
        pointerOneNode->pointerNext = pointerTwoNode->pointerNext;
        free(pointerTwoNode);
    }
    free(head);

    return NULL;
}

ST *reverse(ST *head) {

    ST *auxiliaryPointerOne, *auxiliaryPointerTwo, *auxiliaryPointerThree;
    //初始化指针
    auxiliaryPointerOne = auxiliaryPointerTwo = auxiliaryPointerThree = NULL;
    if (head == NULL || head->pointerNext == NULL)
        return head;//如果头节点为空时，或者链表只有一个节点时


    auxiliaryPointerOne = auxiliaryPointerTwo = head;
    while (auxiliaryPointerTwo != NULL) {//从第二个节点到最后一个节点进行循环
        auxiliaryPointerThree = auxiliaryPointerTwo->pointerNext;//
        auxiliaryPointerTwo->pointerNext = auxiliaryPointerOne;//指向前面一个节点
        auxiliaryPointerOne = auxiliaryPointerTwo;//指针向前移动，从第二个到最后一个全部指向前面的节点
        auxiliaryPointerTwo = auxiliaryPointerThree;
    }
    head->pointerNext = NULL;

    return auxiliaryPointerOne;

}

int getSize(ST *head) {
    if (head == NULL)
        return 0;
    int number = 0;//统计个数
    while (head != NULL) {
        head = head->pointerNext;
        number++;
    }
    return number;
}

ST *contain(ST *head, int number) {

    if (head == NULL)
        return NULL;
    while (head != NULL) {
        if (head->number == number) {
            return head;
        }
        head = head->pointerNext;
    }
    return NULL;
}

void change(ST *head, int oldNumber, int newNumber) {
    ST *temporaryPointer = contain(head, oldNumber);
    if (temporaryPointer != NULL) {
        temporaryPointer->number = newNumber;
    }
}

ST *addFirst(ST *head, int number, int newNumber, float newScore) {

    ST *currentNode, *previousNode;
    currentNode = previousNode = NULL;//初始化指针
    currentNode = head;
    while (currentNode != NULL) {//一直循环到最后一个节点
        if (currentNode->number == number) {
            break;
        } else {
            previousNode = currentNode;//记录当前节点
            currentNode = currentNode->pointerNext;//循环到下一个节点
        }
    }
    if (head == currentNode) {
        ST *newNode = (ST *) malloc(sizeof(ST));//分配内存
        newNode->number = newNumber;
        newNode->score = newScore;
        newNode->pointerNext = head;//指向第一个节点
        head = newNode;
    } else {
        ST *newNode = (ST *) malloc(sizeof(ST));
        newNode->score = newScore;
        newNode->number = newNumber;
        newNode->pointerNext = currentNode;
        previousNode->pointerNext = newNode;

    }
    return head;


}

ST *addLast(ST *head, int number, int newNumber, float newScore) {

    ST *nextNode, *currentNode;//定义两个空节点
    nextNode = currentNode = NULL;
    currentNode = head;
    while (currentNode != NULL) {
        if (currentNode->number == number){
            break;
        } else{
            currentNode = currentNode->pointerNext;
        }
    }
    if (currentNode->pointerNext == NULL){
        ST * newNode = (ST *)malloc(sizeof(ST));//分配内存
        newNode->number = newNumber;
        newNode ->score = newScore;
        newNode->pointerNext = NULL;
        currentNode->pointerNext = newNode;//链接
    } else{
        nextNode = currentNode->pointerNext;//记录当前节点的下一个节点的位置
        ST * newNode = (ST *)malloc(sizeof(ST));//分配内存
        newNode->score = newScore;
        newNode->number = newNumber;
        currentNode->pointerNext = newNode;
        newNode->pointerNext = nextNode;

    }
    return head;
}