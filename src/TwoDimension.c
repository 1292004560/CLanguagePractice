#include <stdio.h>
#include <stdlib.h>
//数组作为函数参数，传递的是地址，地址就是指针占4个字节
//函数参数对于数组没有副本机制，为了节约内存，拷贝数组浪费cpu的空间
int main1(void) {

    int array[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    // printf("%p,%p,%p",array,&array,*array);

    //printf("\n%d ,%d ,%d", sizeof(array), sizeof(*&array), sizeof(**array));

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("   %p", &array[i][j]);
        }
        printf("\n");
    }
    printf("\n%p, %p ,%p", array, array + 1, array + 2);//array是一个行指针，指向一行有4个int
    printf("\n%p, %p , %p", *array, *array + 1, *array + 2);//*array是指向第一行第一个元素的指针
    printf("\n %d,%d", sizeof(*array), sizeof(**array));
    return 0;
}

void main2() {

    int array[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    for (int *pointer = &array[0][0]; pointer < &array[0][0] + 12; pointer++) {
        printf("%d , %p\n", *pointer, pointer);
    }

    return;
}

void main3() {

    int array[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    printf("%d\n", sizeof(*array));//array是一个行指针，16个字节，每一行有16个元素
    int (*pointer)[4] = array;//二维数组的指针就是一个指向一维数组的指针，元素是确定的

    int i = 0;
    int j = 0;
    scanf("%d%d", &i, &j);
    printf("%d ,%d ,%d,%d", i, j, pointer[i][j], *(*(pointer + i) + j));

    return;
}
void printOneDimensionArray(int array[10]){
    for (int i = 0; i < 10; ++i) {
        printf("%4d",*(array+i));
    }
    printf("\n");
}

void printTwoDimensionArray(int array[3][4]){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("  %4d",*(*(array+i)+j));
        }
        printf("\n");
    }
}

void main4(void) {

    int oneDimensionArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int twoDimensionArray[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    printOneDimensionArray(oneDimensionArray);
    printTwoDimensionArray(twoDimensionArray);
    return;
}


void usePointerPrintOneDimensionArray(int *pointer,int size){

    for (int i = 0; i < size; ++i) {
        printf("%3d",*pointer);
        pointer++;
    }
}

void usePointerPrintTwoDimensionArray(int (*pointer)[4],int rowSize){
    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%4d",pointer[i][j]);
        }
        printf("\n");
    }
}

void main(void){

    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    usePointerPrintOneDimensionArray(array,10);
    int twoDimension[3][4] = {{1,2,3,4},{1,2,3,4},{1,2,3,4}};
    puts("\n");
    usePointerPrintTwoDimensionArray(twoDimension,3);
    return;
}