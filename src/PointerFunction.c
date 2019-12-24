#include <stdlib.h>
#include <stdio.h>
int A = 100;
int B = 10;

int add(int a, int b) {
    return a + b;
}

int maxElement(int a, int b) {
    return a > b ? a : b;
}

int minElement(int a, int b) {
    return a < b ? a : b;
}

//函数指针参数名可以省略
//函数指针，不仅仅是地址，必须明确函数指针类型，知道输入参数是什么类型有几个
//返回值是什么类型
int run(int a, int b, int (*functionPointer)(int, int)) {

    return functionPointer(a, b);
}
//没有初始化的指针就是野指针，指向不确定的内存地址
void main(void) {

//       int (*addPointer)(int ,int);
//    addPointer = add;//指针只能传递地址
//
//    printf("%d\n",addPointer(1,2));

    int number;
    scanf("%d", &number);
    switch (number) {
        case 1:
            printf("%d", run(A, B, maxElement));//函数名作为实际参数
            break;
        case 2:
            printf("%d", run(A, B, add));
            break;
        case 3:
            printf("%d",run(A,B,minElement));
            break;
        default:
            printf("错误");
            exit(0);
    }
    return;
}

