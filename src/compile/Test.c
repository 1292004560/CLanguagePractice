#include "../Header/LinkedListStack.h"

int main() {


    Stack *pointerHead = initStack();//����ջΪ��
//    if (pointerHead == NULL){
//        printf("��");
//    }
    printf("��ջ��\n");
    pointerHead = push(pointerHead, 1, 1);
    pointerHead = push(pointerHead, 1, 2);
    pointerHead = push(pointerHead, 1, 3);
    printAllNode(pointerHead);
    {
        Stack *pointerOutData = (Stack *) malloc(sizeof(Stack));
        pointerHead = pop(pointerHead, pointerOutData);
        printf("\n��ջ��:\n");
        printAllNode(pointerHead);
    }
    return 0;
}
