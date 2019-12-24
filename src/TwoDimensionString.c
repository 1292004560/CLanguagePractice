#include "Header/TwoDimenionString.h"

int stringLength(char *pointer) {
    if (pointer == NULL) {
        return -1;//失败
    }

    int length = 0;
    while (*pointer != '\0') {
        pointer++;
        length++;
    }
    return length;
}

char *stringCopy(char *dest, const char *source) {
    //限定不被意外修改

    if (dest == NULL || source == NULL) {
        return NULL;
    }
    char *backPointerUp = dest;
    while (*source != '\0') {
        *dest = *source;
        source++;
        dest++;
    }
    *dest = '\0';//结尾

    return backPointerUp;
}

char *stringConcatenate(char *dest, char *source) {
    if (dest == NULL || source == NULL) {
        return NULL;
    } else {
        char *destBackup = dest;
        while (*dest != '\0') {
            dest++;//指针向前移动
        }
        while (*source != '\0') {
            *dest = *source;
            dest++;
            source++;
        }
        *dest = '\0';
        return destBackup;
    }

}

char *findFirstCharacter( char *dest, char character) {

    if (dest == NULL)
        return NULL;

    while (*dest != '\0') {
        if (*dest == character) {
            return dest;//找到返回地址
        }
        dest++;
    }
    return NULL;
}

char *findFirstString( char *const dest,  char *const findString) {

    if (dest == NULL || findString ==NULL){
        return NULL;
    }

    char *destBackup = dest;
    char *pointer = NULL;//保存找到的地址
    while (*destBackup != '\0') {
        int flag = 1;//假定是相等
        char *findStringBackup = findString;
        char *nowDestBackup = destBackup;
        while (*findStringBackup != '\0') {
            if (*nowDestBackup != '\0') {
                if (*findStringBackup != *nowDestBackup) {
                    //有一个不等
                    flag = 0;//赋值0代表不等
                }
                nowDestBackup++;
                findStringBackup++;
            } else{
                flag = 0;
                break;
            }
        }
        if (flag == 1){
            pointer = destBackup;//当前位置
            return pointer;
        }
        destBackup++;
    }
}

void init(MyString *string) {

    string->pointer = NULL;
    string->reallyLength = 0;//初始化结构体字符串


}//原封不动初始化

void initWithLength(MyString *string, int length) {

    //string ->pointer = (char *)malloc(sizeof(char)*length);//分配内存
    string->pointer = (char *) calloc(length, sizeof(char));//分配内存并清0
    string->reallyLength = length + 1;//长度

}//开辟长度

void initWithString(MyString *string, char *copyString) {

    int length = strlen(copyString);//获取字符串长度
    string->reallyLength = length;//初始化字符串长度
    string->pointer = (char *) calloc(length + 1, sizeof(char));// 分配内存
    stringCopy(string->pointer, copyString);//拷贝字符串
}//初始化并拷贝字符串

//尾部增加字符
void backAddCharacter(MyString *string, char addCharacter) {

    if (strlen(string->pointer) + 1 == string->reallyLength) {
        //意味着满了
        string->pointer = realloc(string->pointer, string->reallyLength + 1);//重新分配内存

        string->reallyLength += 1;//维护reallyLength

        string->pointer[string->reallyLength - 2] = addCharacter;
        string->pointer[string->reallyLength - 1] = '\0';
    } else {
        int currentLength = stringLength(string->pointer);
        string->pointer[currentLength] = addCharacter;
        string->pointer[currentLength + 1] = '\0';
    }

}

void backAddString(MyString *string, char *characterArray) {
    int nowStringLength = stringLength(string->pointer);//获取当前长度
    int addStringLength = stringLength(characterArray);//要增加的长度
    if (nowStringLength + addStringLength + 1 > string->reallyLength) {
        int needAddStringLength = nowStringLength + addStringLength + 1 - string->reallyLength;
        string->pointer = (char *) realloc(string->pointer, string->reallyLength + needAddStringLength);//增加字符串长度
        strcat(string->pointer, characterArray);//拷贝字符串
        string->reallyLength += needAddStringLength;
    } else {
        strcat(string->pointer, characterArray);//拷贝字符串
    }
}

void printString(MyString *string) {
    printf("\n%s", string->pointer);//打印字符串
}

void run(MyString *string) {
    system(string->pointer);//执行指令
}

char *findStringFirstCharacter(MyString *string, char character) {
    char *pointer = strchr(string->pointer, character);
    return pointer;
}

char *findStringFirstString(MyString *string, char *findString) {
    char *resultPointer = findFirstString(string->pointer, findString);

    return resultPointer;
}

int deleteFirstCharacter(MyString *string,char deleteCharacter){
    char * pointer = findFirstCharacter(string->pointer,deleteCharacter);//查找
    if (pointer == NULL){
        return 0;
    } else {
        char *pointerNext = pointer + 1;
        while (*pointerNext != '\0') {
            *pointer = *pointerNext;
            pointer++;
            pointerNext++;
        }
        *pointer = '\0';
        return 1;
    }
}

int deleteFirstString(MyString *string, char * deleteString){
    char * pointer = findStringFirstString(string,deleteString);//查找
    if (pointer == NULL){
        return 0;
    } else{
      int length = strlen(deleteString);//求字符串长度
      char  * pointerNext = pointer + length;// 下一个字符串长度
      while(*pointerNext != '\0'){
            *pointer = *pointerNext;
            pointer++;
            pointerNext++;
      }
      *pointer = '\0';//字符串要结尾
      return 1;
    }
}

void addCharacter(MyString *myString,char character,char * position){
        if(position == NULL || myString == NULL)
            return ;
        if (stringLength(myString->pointer)+1 == myString->reallyLength){
            //意味着满了
            //重新分配内存
            myString->pointer = realloc(myString->pointer,myString->reallyLength+1);
            //维护reallyLength
            myString->reallyLength+=1;
            int nowLength = stringLength(myString->pointer);
            int moveLength = stringLength(position);
            for (int i = nowLength; i > nowLength - moveLength ; i--) {
                myString->pointer[i] = myString->pointer[i-1];
            }
            myString->pointer[nowLength-moveLength] = character;//插入
            myString->pointer[nowLength+1] = '\0';//字符串结尾
        } else{
            int nowLength = stringLength(myString->pointer);//求出当前长度
            int moveLength = stringLength(position);//要移动的长度
            for (int i = nowLength; i >nowLength-moveLength ; i--) {
                myString->pointer[i] = myString->pointer[i-1];
            }
            myString->pointer[nowLength-moveLength] = character;
            myString->pointer[nowLength+1] = '\0';

        }

}

void addString(MyString * myString,char * string,char * position){
    if (myString == NULL || string == NULL || position == NULL)
        return;
    int nowStringLength = stringLength(myString->pointer);//获取当前长度
    int addStringLength = stringLength(string);//要增加的长度
    if (nowStringLength + addStringLength + 1 > myString->reallyLength) {
        int needAddStringLength = nowStringLength + addStringLength + 1 - myString->reallyLength;
        myString->pointer = (char *) realloc(myString->pointer, myString->reallyLength + needAddStringLength);//增加字符串长度
        //移动，拷贝
        int nowLength = stringLength(myString->pointer);//求出当前长度
        int moveLength = stringLength(position);//求出现在要移动的长度
        int insertLength = stringLength(string);
        for (int i = nowLength; i >= nowLength-moveLength ; i--) {

            myString->pointer[i+insertLength] = myString->pointer[i];
        }
        for (int i = 0; i < insertLength; ++i) {
           myString->pointer[nowLength-moveLength+i] = string[i];//赋值拷贝

        }
        myString->reallyLength += needAddStringLength;
    } else {

        int nowLength = stringLength(myString->pointer);//求出当前长度
        int moveLength = stringLength(position);//求出现在要移动的长度
        int insertLength = stringLength(string);
        for (int i = nowLength; i >= nowLength-moveLength ; i--) {

            myString->pointer[i+insertLength] = myString->pointer[i];
        }
        for (int i = 0; i < insertLength; ++i) {
            myString->pointer[nowLength-moveLength+i] = string[i];//赋值拷贝
        }

    }
}

void changeFirstCharacter(MyString * myString, const char oldCharacter, const char newCharacter){
    char * pointer = myString->pointer;
    while (*pointer != '\0'){
        if (*pointer == oldCharacter){
            *pointer = newCharacter;
            return;
        }
        pointer++;
    }
}

void changeFirstString(MyString * myString, char *const oldString , char *const newString) {
    char *pointerFind = findStringFirstString(myString, oldString);
    if (pointerFind != NULL) {
        deleteFirstString(myString, oldString);
        addString(myString,newString,pointerFind);
    }
}