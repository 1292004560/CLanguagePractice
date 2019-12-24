#include <stdio.h>
#include <stdlib.h>

void readFile(char * path){
    FILE * pointer = fopen(path,"r");//二进制方式读取，原封不动
    char c;//定义一个字符
    fread(&c,1,1,pointer);
    while (!feof(pointer)){
        //没有结束就继续
        printf("%d",c);
        fread(&c,1,1,pointer);

    }
    fclose(pointer);//关闭文件
}

void main(void){
    int W = getw(stdin);//从键盘中获取输入
    putw(W,stdout);//显示器输出
}

void  main14(void){

    fprintf(stderr,"error");
    return;
}


void main13(void){

    char string[50] ;
   // gets(string);
   fgets(string, sizeof(string)-1,stdin);
    fputs(string,stdout);
    return;
}


void main12(void){

    int number1;
    scanf("%d",&number1);
    printf("%d\n",number1);

    int number2 ;
    fscanf(stdin,"%d",&number2);//fscanf可以扫描任何文件，不仅仅是键盘
    //scanf是fscanf的特列
    fprintf(stdout,"%d",number2);
}

void main11(void){

    putchar('A');
    fputc('A',stdout);
    //putchar是fputc的特列
    return;
}

void main10 (void){

    puts("你好");
    fputs("你好",stdout);
    //puts只是fputs的特列只能输出到显示器
    //fputs可以输出到任何文件

    return;
}

void main9(void){

    printf("\n沙雕\n");
    fprintf(stdout,"\n沙雕\n");
    //显示器当做文件来操作，fprintf()可以输出到任何文件
    //printf只是fprintf的特列，只能输出到屏幕
    return;
}

void main8(void){

    char character;
    printf("缓冲区的有效数据是%d\n",stdin->_cnt);
    printf("指向缓冲区的指针%p\n",stdin->_ptr);
    printf("缓冲区的起始地址%p\n",stdin->_base);
    printf("缓冲区的大小%d\n",stdin->_bufsiz);
    printf("缓冲区的文件提示符%d\n",stdin->_file);

    character = getchar();
    printf("当前获取的字符是%c\n",character);
    printf("缓冲区的有效数据是%d\n",stdin->_cnt);
    printf("指向缓冲区的指针%p\n",stdin->_ptr);
    printf("缓冲区的起始地址%p\n",stdin->_base);
    printf("缓冲区的大小%d\n",stdin->_bufsiz);
    printf("缓冲区的文件提示符%d\n",stdin->_file);
    character = getchar();
    printf("缓冲区的有效数据是%d\n",stdin->_cnt);
    printf("指向缓冲区的指针%p\n",stdin->_ptr);
    printf("缓冲区的起始地址%p\n",stdin->_base);
    printf("缓冲区的大小%d\n",stdin->_bufsiz);
    printf("缓冲区的文件提示符%d\n",stdin->_file);
    character = getchar();
    fflush(stdin);//有效数据清零
    printf("缓冲区的有效数据是%d\n",stdin->_cnt);
    printf("指向缓冲区的指针%p\n",stdin->_ptr);
    printf("缓冲区的起始地址%p\n",stdin->_base);
    printf("缓冲区的大小%d\n",stdin->_bufsiz);
    printf("缓冲区的文件提示符%d\n",stdin->_file);
    rewind(stdin);//文件回到开头  有效数据清零，指针回到起始地址

    return;
}

void main7(void){

    char * path = "c:\\a.txt";
    FILE * pointerFile = fopen(path,"r");
    char doCmd[100] = {0};
    int number = 0;
    if (pointerFile == NULL){
        printf("文件打开失败");
    } else{
        fscanf(pointerFile,"for / l %%i in (1,1,%d) do %s",&number,doCmd);//读取字符串
        printf("number = %d ,doCmd = %d",number,doCmd);
    }
    return;
}

void main6(void){
    char * path = "C:\\a.txt";

    int number = 0;
    char doCommand[100] = {0};

    scanf("%d%s",&number,doCommand);
    char command[100] = {0};
    FILE * pointerFile = fopen(path,"w");//写入

    if (pointerFile == NULL){
        printf("文件打开失败");
    } else{
        fprintf(pointerFile,"for / l %%i in (1,1,%d) do %s",number,doCommand);
        fclose(pointerFile);
    }


    return;
}


void main5(void){

    char string[100] = {0};
    fscanf(stdin,"%s",string);
    fprintf(stdout,"string=%s\n",string);
    system(string);


    return;
}


void main4(void){

    FILE * pointerFile ;
    pointerFile = fopen("C:\\a.txt","wb");
    if (pointerFile == NULL){
        printf("文件打开失败");
    } else{
        printf("文件打开成功");
        fputs("周水平你好",pointerFile);
        fflush(pointerFile);//强制将文件缓冲区的内容写入文件
        fputs("\r\n沙雕",pointerFile);
    }
    fclose(pointerFile);

    return;
}

void main2(void) {

    char buffer[5] = {10, 10, 10, 10, 10};
    FILE * pointerFileText ;//代表文本，ASCII码表
    FILE * pointerFileBinary;//代表二进制文件

    char pathText[40] = "E:\\Cfirst\\a.c";
    char pathBinary[40] = "E:\\Cfirst\\b.c";

    pointerFileText = fopen(pathText,"w");//按照文本写入的模式打开
    if (pointerFileText == NULL){
        printf("文件打开失败\n");
    } else{
        fwrite(buffer,1,5,pointerFileText);
        fclose(pointerFileText);
    }

    pointerFileBinary = fopen(pathBinary,"wb");
    if (pointerFileBinary == NULL){
        printf("二进制文件打开失败\n");
    } else{
        fwrite(buffer,1,5,pointerFileBinary);
        fclose(pointerFileBinary);
    }

    printf("\n");
    printf("文本写入读取的内容");
    printf("\n");
    readFile(pathText);

    printf("\n");
    printf("二进制写入读取的内容");
    printf("\n");
    readFile(pathBinary);

    return;
}


void main1(void) {

    char string[100] = "你好";
//    puts(string);
    fputs(string, stdout);//stdout就是显示器，通过文件读写的方式，写入一个字符串


    return;
}
