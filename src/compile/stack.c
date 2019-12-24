
#include <stdio.h>
#include <stdlib.h>

#define N 100

//定义栈的结构体
struct Stack{
    int top;//统计栈有多少个元素，data[top]是栈顶
    int data[N];//数组用于存放数据

};

struct Stack myStack = {-1,{0}};
//-1代表栈中没有元素 {0}将数组的元素初始化为0

int isEmpty();//判断栈是否为空
void setEmpty();//设置栈为空
int push(int element);//压入一个数据
int pop();//取出一个数据

int isEmpty(){

    if (myStack.top == -1){
        return 1;
    } else{
        return 0;
    }
}

void setEmpty(){
    myStack.top = -1;
}

int push(int element){
    //成功返回1，否则返回0
    if (myStack.top + 1 <= N-1){
        myStack.data[myStack.top+1] = element;
        myStack.top++;
        return 1;
    } else{
        return 0;
    }
}

int pop(){
    if (isEmpty()){
        return -1;
    } else{
        int result = myStack.data[myStack.top];
        myStack.top --;
        return result;
    }
}

int main(void){

    for (int i = 0; i <10 ; ++i) {
        push(i);
    }

    while (!isEmpty()){
        printf("%d\n",pop());
    }

    return 0;
}