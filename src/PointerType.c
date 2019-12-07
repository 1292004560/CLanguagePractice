
#include <stdio.h>
#include <stdlib.h>

int main01(void){

    int number = 100;

    int * p1 = &number;

    int * p2 = p1;

    printf("%d,%d,%d",number,*p1,*p2);
    printf("\n%x, %x ,%x",&number,p1,p2);

    *p1 = 90;
    printf("\n%d,%d,%d",number,*p1,*p2);
    printf("\n%x, %x ,%x",&number,p1,p2);
    return 0;
}

int main(void){

    int array[10] = {1,2,3,4,5,6,7,8,9,10};
    printf("%d\n",array);
    int * p = array;
    p++;
    printf("%d\n",*(p +1));
    return 0;
}

