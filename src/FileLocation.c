#include <stdio.h>
#include <stdlib.h>
#include <io.h>


void main(){

    char oldName[100] = "c:\\a.txt";
    char newName[100] = "c:\\c.txt";
    if (rename(oldName,newName) == 0){
        printf("改名成功");
    }
    return;
}

void main12(void){

    getchar();//获取一个字符输入
    printf("%p\n",stdin->_base);//键盘输入缓冲区的基地址
    printf("%p\n",stdin->_ptr);//键盘输入缓冲区的当前地址
    printf("%d\n",*stdin->_ptr);//取出当前缓冲区的内容
    printf("%d\n",*stdin->_ptr);//取出当前缓冲区的内容
    printf("%d\n",*++stdin->_ptr);//取出当前缓冲区的内容

    //getchar获取字符之后，指针向后移动一位
    return;

}

void main11(void){

    char c = getchar();
    printf("第一次输入的是%c\n",c);
    setvbuf(stdin,NULL,_IONBF,0);//设置键盘输入没有缓冲
    printf("缓冲区大小%d\n",stdin->_bufsiz);
    printf("缓冲区保存的字符%c,%d",stdin->_charbuf,stdin->_charbuf);
    //charbuf是一个双字节缓冲
    printf("缓冲区未读的字符数%d\n",stdin->_cnt);
    printf("缓冲区的基地址%p\n",stdin->_base);
    printf("缓冲区的当前地址%p\n",stdin->_ptr);
    printf("缓冲区当前的内容%c\n",*stdin->_ptr);
    return;
}

void main10(void){

    FILE * pointerTemporaryFile;//创建一个文件指针
    char path[100];//路径，保存临时文件名
    tmpnam(path);//生成一个临时文件名保存到path
    pointerTemporaryFile = fopen(path,"w+");
    printf("路径是%s\n",path);
    if (pointerTemporaryFile == NULL){
        printf("文件打开失败");
    }
    fputs("周水平",pointerTemporaryFile);
    fputs("熊声亮",pointerTemporaryFile);
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
    pointerTemporaryFile = tmpfile();//创建临时文件，返回文件指针
    if (pointerTemporaryFile == NULL){
        printf("创建失败\n");
        return;
    } else{

        fputs("沙雕",pointerTemporaryFile);
    }
    rewind(pointerTemporaryFile);//回到文件开头
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
        perror("文件错误");
    }
    while (!feof(pointerFileRead)) {
        char character = fgetc(pointerFileRead);//读取文本
        character = character+1;//字符移位加密
        fputc(character, pointerFileWrite);//写入文本
    }
    fclose(pointerFileRead);
    fclose(pointerFileWrite);
    return;
}

void main6(void) {

    FILE *pointerFile = fopen("c:\\b.txt", "r");

    if (pointerFile == NULL) {
        perror("文件打开失败\n");
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
            } else if (numberCharacter > 128) {//判定位双字节字符
                numberCharacter = fgetc(pointerFile);//因为是双字节字符，所以还要前进一位
                numberChinese++;
            }
        }
        printf("字符总数 = %d,数字 = %d ,字母 = %d,中文 = %d\n", numberCharacter, number, numberEnglish, numberChinese);
        fclose(pointerFile);
    }

    return;
}

void main7(void) {

    printf("%d", sizeof("我"));
    fprintf(stdout, "大小 = %d\n", sizeof(int));
    return;
}

int main5(void) {

    FILE *pointerFile = fopen("D:\\Eclipse\\eclipse--Java\\javaProject\\src\\www\\com\\Cat.java", "r");
    if (pointerFile == NULL) {
        printf("文件打开失败");
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
        printf("大写字母 = %d ,小写字母个数 = %d\n", uppercaseNumber, lowercaseNumber);
        fclose(pointerFile);
    }
    return 0;
}

void main4(void) {

    char soleFileName[100] = "c:\\XXXXXX";//修改的目标,后面必须为XXXXXX

    char *newName = _mktemp(soleFileName);//传入路径，根据模板生成唯一的目录名
    printf("%s,%s", newName, soleFileName);//初始化字符串
    char command[100];
    sprintf(command, "md %s", soleFileName);//初始化字符串，用于指令创建目录
    system(command);
    return;
}

void main3(void) {

    char *fileName = "c:\\a.txt";
    remove(fileName);


    return;
}

void main2(void) {

    FILE *pointerFile = fopen("c:\\b.txt", "r+");//以读写的方式打开文件
    if (pointerFile == NULL) {
        printf("文件打开失败");
    } else {
        printf("打开成功\n");
        fseek(pointerFile, 0, SEEK_END);//移动指针到末尾
        fputs("沙雕", pointerFile);

        fclose(pointerFile);
    }


    return;
}

int main1(void) {

    FILE *pointerFile = fopen("c:\\b.txt", "r");
    if (pointerFile == NULL) {
        printf("文件打开失败");
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
