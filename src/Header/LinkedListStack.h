

#ifndef PRACTISE_LINKEDLISTSTACK_H
#define PRACTISE_LINKEDLISTSTACK_H
#define DataType int

#include <stdio.h>
#include <stdlib.h>
 struct stack{
    int number;//编号
    DataType data;//数据
    struct stack * pointerNext;
};
typedef struct stack Stack;

Stack  * initStack();

Stack * push(Stack * pointerHead,int number,DataType data);//入栈

Stack * pop (Stack * pointerHead,Stack * pointerOutData);//出栈

Stack * freeAll(Stack * pointerHead);//清空

void printAllNode(Stack * pointerHead);





#endif //PRACTISE_LINKEDLISTSTACK_H
