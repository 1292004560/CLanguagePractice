#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void change(int * p1,int *p2){

    int templateElement = *p2;
    *p2 = *p1;
    *p1 = templateElement;
}

int main(void) {

    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    //printf("%d", *(array + 2));

    time_t systemTime;//时间的数据类型

    srand((unsigned int)time(&systemTime));//以时间作为随机数种子

    int numbers[10];
    for (int i = 0; i < 10; ++i) {
        numbers[i] = rand() % 100;//0-99的随机数
        printf("%3d , %4x\n",numbers[i],numbers+i);
    }

    int * pointer = numbers;
    int maxElement = 0;
    for (int i = 0; i < 10; ++i) {
        if (*pointer > maxElement){
            maxElement = *pointer;
        }
        pointer++;
    }

    printf("%d\n",maxElement);

    int a = 1;
    int b = 2;
    printf("a = %d ,b = %d\n",a,b);
    change(&a,&b);
    printf("a = %d,b = %d\n",a,b);

    
    return 0;
}

