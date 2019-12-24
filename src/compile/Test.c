#include "../Header/LinkedListStack.h"

int main() {


    Stack *pointerHead = initStack();//设置栈为空
//    if (pointerHead == NULL){
//        printf("鸟");
//    }
    printf("入栈：\n");
    pointerHead = push(pointerHead, 1, 1);
    pointerHead = push(pointerHead, 1, 2);
    pointerHead = push(pointerHead, 1, 3);
    printAllNode(pointerHead);
    {
        Stack *pointerOutData = (Stack *) malloc(sizeof(Stack));
        pointerHead = pop(pointerHead, pointerOutData);
        printf("\n出栈后:\n");
        printAllNode(pointerHead);
    }
    return 0;
}
