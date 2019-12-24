
#include <stdlib.h>
#include <stdio.h>
#define cn "你好世界"
#define en "hello world"
#define ADD(x) 3*x
#define B 1   //定义一个宏有选择的编译语句   ，例如一套代码同时应对两个环境


void main(void){

    printf("当前文件名%s\n",__FILE__);
    printf("当前语句所在%d行\n",__LINE__);
    printf("当前的函数名%s\n",__FUNCTION__);
    return;
}

void main1(void){
#undef B
#if B == 1
    printf(cn);
#else
    printf(en);
#endif

    printf("%d\n",ADD(2));
    return;
}

