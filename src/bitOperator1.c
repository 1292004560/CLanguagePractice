#include <stdio.h>

void main(void){

    unsigned char ch = 1;
    printf("%d\n",ch<<1);
    printf("%d\n",ch<<2);
    printf("%d\n",ch);
    //左移一位，等价于乘于2
    printf("%d\n",8<<1);
    printf("%d\n",ch = (ch<<10));//左移要考虑数据的溢出
    printf("%d\n",ch>>1);
    return;
}
