//#define DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>//��̬���Ե�ͷ�ļ�
#ifndef DEBUG
#define myAssert(x) //Ϊ��  //û�д������
#else
#define myAssert(x)\
if (!(x))\
        {\
        printf("myAssert(%s)��ʼ���.....\n",#x);\
        printf("��ǰ������Ϊ%s���ļ���Ϊ%s�������к�Ϊ%d",__FUNCTION__,__FILE__,__LINE__);\
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