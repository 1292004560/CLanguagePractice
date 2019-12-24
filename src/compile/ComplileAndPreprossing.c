//#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>//静态断言的头文件
#ifndef DEBUG
#define myAssert(x) //为空  //没有代码测试
#else
#define myAssert(x)\
if (!(x))\
        {\
        printf("myAssert(%s)开始检测.....\n",#x);\
        printf("当前函数名为%s，文件名为%s，代码行号为%d",__FUNCTION__,__FILE__,__LINE__);\
        }
#endif
void main(void){

    double  a ,b;
    scanf("%lf%lf",&a,&b);
    printf("a = %lf,b = %lf\n",a,b);

    myAssert(b!=0);
    printf("a/b = %f ",a/b);
    return;
}