#include <stdio.h>
#include <stdlib.h>

void readFile(char * path){
    FILE * pointer = fopen(path,"r");//�����Ʒ�ʽ��ȡ��ԭ�ⲻ��
    char c;//����һ���ַ�
    fread(&c,1,1,pointer);
    while (!feof(pointer)){
        //û�н����ͼ���
        printf("%d",c);
        fread(&c,1,1,pointer);

    }
    fclose(pointer);//�ر��ļ�
}

void main(void){
    int W = getw(stdin);//�Ӽ����л�ȡ����
    putw(W,stdout);//��ʾ�����
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
    fscanf(stdin,"%d",&number2);//fscanf����ɨ���κ��ļ����������Ǽ���
    //scanf��fscanf������
    fprintf(stdout,"%d",number2);
}

void main11(void){

    putchar('A');
    fputc('A',stdout);
    //putchar��fputc������
    return;
}

void main10 (void){

    puts("���");
    fputs("���",stdout);
    //putsֻ��fputs������ֻ���������ʾ��
    //fputs����������κ��ļ�

    return;
}

void main9(void){

    printf("\nɳ��\n");
    fprintf(stdout,"\nɳ��\n");
    //��ʾ�������ļ���������fprintf()����������κ��ļ�
    //printfֻ��fprintf�����У�ֻ���������Ļ
    return;
}

void main8(void){

    char character;
    printf("����������Ч������%d\n",stdin->_cnt);
    printf("ָ�򻺳�����ָ��%p\n",stdin->_ptr);
    printf("����������ʼ��ַ%p\n",stdin->_base);
    printf("�������Ĵ�С%d\n",stdin->_bufsiz);
    printf("���������ļ���ʾ��%d\n",stdin->_file);

    character = getchar();
    printf("��ǰ��ȡ���ַ���%c\n",character);
    printf("����������Ч������%d\n",stdin->_cnt);
    printf("ָ�򻺳�����ָ��%p\n",stdin->_ptr);
    printf("����������ʼ��ַ%p\n",stdin->_base);
    printf("�������Ĵ�С%d\n",stdin->_bufsiz);
    printf("���������ļ���ʾ��%d\n",stdin->_file);
    character = getchar();
    printf("����������Ч������%d\n",stdin->_cnt);
    printf("ָ�򻺳�����ָ��%p\n",stdin->_ptr);
    printf("����������ʼ��ַ%p\n",stdin->_base);
    printf("�������Ĵ�С%d\n",stdin->_bufsiz);
    printf("���������ļ���ʾ��%d\n",stdin->_file);
    character = getchar();
    fflush(stdin);//��Ч��������
    printf("����������Ч������%d\n",stdin->_cnt);
    printf("ָ�򻺳�����ָ��%p\n",stdin->_ptr);
    printf("����������ʼ��ַ%p\n",stdin->_base);
    printf("�������Ĵ�С%d\n",stdin->_bufsiz);
    printf("���������ļ���ʾ��%d\n",stdin->_file);
    rewind(stdin);//�ļ��ص���ͷ  ��Ч�������㣬ָ��ص���ʼ��ַ

    return;
}

void main7(void){

    char * path = "c:\\a.txt";
    FILE * pointerFile = fopen(path,"r");
    char doCmd[100] = {0};
    int number = 0;
    if (pointerFile == NULL){
        printf("�ļ���ʧ��");
    } else{
        fscanf(pointerFile,"for / l %%i in (1,1,%d) do %s",&number,doCmd);//��ȡ�ַ���
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
    FILE * pointerFile = fopen(path,"w");//д��

    if (pointerFile == NULL){
        printf("�ļ���ʧ��");
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
        printf("�ļ���ʧ��");
    } else{
        printf("�ļ��򿪳ɹ�");
        fputs("��ˮƽ���",pointerFile);
        fflush(pointerFile);//ǿ�ƽ��ļ�������������д���ļ�
        fputs("\r\nɳ��",pointerFile);
    }
    fclose(pointerFile);

    return;
}

void main2(void) {

    char buffer[5] = {10, 10, 10, 10, 10};
    FILE * pointerFileText ;//�����ı���ASCII���
    FILE * pointerFileBinary;//����������ļ�

    char pathText[40] = "E:\\Cfirst\\a.c";
    char pathBinary[40] = "E:\\Cfirst\\b.c";

    pointerFileText = fopen(pathText,"w");//�����ı�д���ģʽ��
    if (pointerFileText == NULL){
        printf("�ļ���ʧ��\n");
    } else{
        fwrite(buffer,1,5,pointerFileText);
        fclose(pointerFileText);
    }

    pointerFileBinary = fopen(pathBinary,"wb");
    if (pointerFileBinary == NULL){
        printf("�������ļ���ʧ��\n");
    } else{
        fwrite(buffer,1,5,pointerFileBinary);
        fclose(pointerFileBinary);
    }

    printf("\n");
    printf("�ı�д���ȡ������");
    printf("\n");
    readFile(pathText);

    printf("\n");
    printf("������д���ȡ������");
    printf("\n");
    readFile(pathBinary);

    return;
}


void main1(void) {

    char string[100] = "���";
//    puts(string);
    fputs(string, stdout);//stdout������ʾ����ͨ���ļ���д�ķ�ʽ��д��һ���ַ���


    return;
}
