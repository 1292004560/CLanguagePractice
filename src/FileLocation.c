#include <stdio.h>
#include <stdlib.h>
#include <io.h>


void main(){

    char oldName[100] = "c:\\a.txt";
    char newName[100] = "c:\\c.txt";
    if (rename(oldName,newName) == 0){
        printf("�����ɹ�");
    }
    return;
}

void main12(void){

    getchar();//��ȡһ���ַ�����
    printf("%p\n",stdin->_base);//�������뻺�����Ļ���ַ
    printf("%p\n",stdin->_ptr);//�������뻺�����ĵ�ǰ��ַ
    printf("%d\n",*stdin->_ptr);//ȡ����ǰ������������
    printf("%d\n",*stdin->_ptr);//ȡ����ǰ������������
    printf("%d\n",*++stdin->_ptr);//ȡ����ǰ������������

    //getchar��ȡ�ַ�֮��ָ������ƶ�һλ
    return;

}

void main11(void){

    char c = getchar();
    printf("��һ���������%c\n",c);
    setvbuf(stdin,NULL,_IONBF,0);//���ü�������û�л���
    printf("��������С%d\n",stdin->_bufsiz);
    printf("������������ַ�%c,%d",stdin->_charbuf,stdin->_charbuf);
    //charbuf��һ��˫�ֽڻ���
    printf("������δ�����ַ���%d\n",stdin->_cnt);
    printf("�������Ļ���ַ%p\n",stdin->_base);
    printf("�������ĵ�ǰ��ַ%p\n",stdin->_ptr);
    printf("��������ǰ������%c\n",*stdin->_ptr);
    return;
}

void main10(void){

    FILE * pointerTemporaryFile;//����һ���ļ�ָ��
    char path[100];//·����������ʱ�ļ���
    tmpnam(path);//����һ����ʱ�ļ������浽path
    pointerTemporaryFile = fopen(path,"w+");
    printf("·����%s\n",path);
    if (pointerTemporaryFile == NULL){
        printf("�ļ���ʧ��");
    }
    fputs("��ˮƽ",pointerTemporaryFile);
    fputs("������",pointerTemporaryFile);
    rewind(pointerTemporaryFile);
    char string[512];
    fgets(string,512,pointerTemporaryFile);
    printf("%s\n",string);
    fclose(pointerTemporaryFile);
    system("pause");
    return;
}

void main9(void){

    FILE * pointerTemporaryFile ;
    pointerTemporaryFile = tmpfile();//������ʱ�ļ��������ļ�ָ��
    if (pointerTemporaryFile == NULL){
        printf("����ʧ��\n");
        return;
    } else{

        fputs("ɳ��",pointerTemporaryFile);
    }
    rewind(pointerTemporaryFile);//�ص��ļ���ͷ
    char string[512];
    fgets(string,512,pointerTemporaryFile);
    puts(string);
    fclose(pointerTemporaryFile);
    return;
}

void main8(void) {
    FILE *pointerFileWrite;
    FILE *pointerFileRead;
    char pathRead[100] = "c:\\a.txt";
    char pathWrite[100] = "c:\\b.txt";
    pointerFileRead = fopen(pathRead, "r");
    pointerFileWrite = fopen(pathWrite, "w");
    if (pointerFileRead == NULL || pointerFileWrite == NULL) {
        perror("�ļ�����");
    }
    while (!feof(pointerFileRead)) {
        char character = fgetc(pointerFileRead);//��ȡ�ı�
        character = character+1;//�ַ���λ����
        fputc(character, pointerFileWrite);//д���ı�
    }
    fclose(pointerFileRead);
    fclose(pointerFileWrite);
    return;
}

void main6(void) {

    FILE *pointerFile = fopen("c:\\b.txt", "r");

    if (pointerFile == NULL) {
        perror("�ļ���ʧ��\n");
    } else {
        int numberEnglish = 0;
        int numberCharacter = 0;
        int number = 0;
        int numberChinese = 0;
        while ((numberCharacter = fgetc(pointerFile)) != EOF) {
            if ((numberCharacter >= 'A' && numberCharacter <= 'Z') ||
                (numberCharacter < 'z' && numberCharacter >= 'a')) {
                numberEnglish++;
            } else if (numberCharacter >= '0' && numberCharacter <= '9') {
                number++;
            } else if (numberCharacter > 128) {//�ж�λ˫�ֽ��ַ�
                numberCharacter = fgetc(pointerFile);//��Ϊ��˫�ֽ��ַ������Ի�Ҫǰ��һλ
                numberChinese++;
            }
        }
        printf("�ַ����� = %d,���� = %d ,��ĸ = %d,���� = %d\n", numberCharacter, number, numberEnglish, numberChinese);
        fclose(pointerFile);
    }

    return;
}

void main7(void) {

    printf("%d", sizeof("��"));
    fprintf(stdout, "��С = %d\n", sizeof(int));
    return;
}

int main5(void) {

    FILE *pointerFile = fopen("D:\\Eclipse\\eclipse--Java\\javaProject\\src\\www\\com\\Cat.java", "r");
    if (pointerFile == NULL) {
        printf("�ļ���ʧ��");
    } else {
        char character;
        int uppercaseNumber = 0;
        int lowercaseNumber = 0;
        while ((character = fgetc(pointerFile)) != EOF) {
            if (character <= 'Z' && character >= 'A')
                uppercaseNumber++;
            else if (character >= 'a' && character <= 'z')
                lowercaseNumber++;
        }
        printf("��д��ĸ = %d ,Сд��ĸ���� = %d\n", uppercaseNumber, lowercaseNumber);
        fclose(pointerFile);
    }
    return 0;
}

void main4(void) {

    char soleFileName[100] = "c:\\XXXXXX";//�޸ĵ�Ŀ��,�������ΪXXXXXX

    char *newName = _mktemp(soleFileName);//����·��������ģ������Ψһ��Ŀ¼��
    printf("%s,%s", newName, soleFileName);//��ʼ���ַ���
    char command[100];
    sprintf(command, "md %s", soleFileName);//��ʼ���ַ���������ָ���Ŀ¼
    system(command);
    return;
}

void main3(void) {

    char *fileName = "c:\\a.txt";
    remove(fileName);


    return;
}

void main2(void) {

    FILE *pointerFile = fopen("c:\\b.txt", "r+");//�Զ�д�ķ�ʽ���ļ�
    if (pointerFile == NULL) {
        printf("�ļ���ʧ��");
    } else {
        printf("�򿪳ɹ�\n");
        fseek(pointerFile, 0, SEEK_END);//�ƶ�ָ�뵽ĩβ
        fputs("ɳ��", pointerFile);

        fclose(pointerFile);
    }


    return;
}

int main1(void) {

    FILE *pointerFile = fopen("c:\\b.txt", "r");
    if (pointerFile == NULL) {
        printf("�ļ���ʧ��");
    } else {
        while (!feof(pointerFile)) {
            char character = fgetc(pointerFile);
            putchar(character);
        }
        printf("-------------------------------\n");
        rewind(pointerFile);
        char string[100] = {0};
        while (fgets(string, 10000, pointerFile) != NULL) {
            printf("%s\n", string);
        }
    }
    fclose(pointerFile);
    return 0;
}
