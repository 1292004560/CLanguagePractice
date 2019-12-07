#include <stdio.h>

double MAX = 100.0;
int main01(void) {

    printf("%x\n", main01);
    int number = 10;
    int *pointer = &number;
    *pointer = 100;
    printf("%d", *(&number));
    return 0;
}
int main1(void){

    int number = 100;
    int * pointer = &number;
    printf("%p",pointer);

    int  *a,*b,*c;
    printf("\n %d ,%d ,%d\n", sizeof(a), sizeof(b), sizeof(c));
    printf("%x , %p",pointer,pointer);


    //getchar();

    return 0;
}

int main011(void){

    int number1 = 100;
    int number2 = 1000;
    printf("%p,%p",&number1,number2);

    int * pointer = NULL;

    scanf("%p",&pointer);

    printf("%p,%d",pointer,*pointer);


    return 0;
}

void change(double **p){
    *p = &MAX;
}
int main(void){

    double number = 10.8;
    double *p = &number;

    //double **p1 = &p;
    change(&p);

    printf("%f\n",*p);
    double a = 1.00;
    printf("%f",a);




    return 0;
}


