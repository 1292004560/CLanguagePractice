
#include <stdlib.h>
#include <stdio.h>
#define cn "�������"
#define en "hello world"
#define ADD(x) 3*x
#define B 1   //����һ������ѡ��ı������   ������һ�״���ͬʱӦ����������


void main(void){

    printf("��ǰ�ļ���%s\n",__FILE__);
    printf("��ǰ�������%d��\n",__LINE__);
    printf("��ǰ�ĺ�����%s\n",__FUNCTION__);
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

