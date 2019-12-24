#include "Header/TwoDimenionString.h"

int stringLength(char *pointer) {
    if (pointer == NULL) {
        return -1;//ʧ��
    }

    int length = 0;
    while (*pointer != '\0') {
        pointer++;
        length++;
    }
    return length;
}

char *stringCopy(char *dest, const char *source) {
    //�޶����������޸�

    if (dest == NULL || source == NULL) {
        return NULL;
    }
    char *backPointerUp = dest;
    while (*source != '\0') {
        *dest = *source;
        source++;
        dest++;
    }
    *dest = '\0';//��β

    return backPointerUp;
}

char *stringConcatenate(char *dest, char *source) {
    if (dest == NULL || source == NULL) {
        return NULL;
    } else {
        char *destBackup = dest;
        while (*dest != '\0') {
            dest++;//ָ����ǰ�ƶ�
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
            return dest;//�ҵ����ص�ַ
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
    char *pointer = NULL;//�����ҵ��ĵ�ַ
    while (*destBackup != '\0') {
        int flag = 1;//�ٶ������
        char *findStringBackup = findString;
        char *nowDestBackup = destBackup;
        while (*findStringBackup != '\0') {
            if (*nowDestBackup != '\0') {
                if (*findStringBackup != *nowDestBackup) {
                    //��һ������
                    flag = 0;//��ֵ0������
                }
                nowDestBackup++;
                findStringBackup++;
            } else{
                flag = 0;
                break;
            }
        }
        if (flag == 1){
            pointer = destBackup;//��ǰλ��
            return pointer;
        }
        destBackup++;
    }
}

void init(MyString *string) {

    string->pointer = NULL;
    string->reallyLength = 0;//��ʼ���ṹ���ַ���


}//ԭ�ⲻ����ʼ��

void initWithLength(MyString *string, int length) {

    //string ->pointer = (char *)malloc(sizeof(char)*length);//�����ڴ�
    string->pointer = (char *) calloc(length, sizeof(char));//�����ڴ沢��0
    string->reallyLength = length + 1;//����

}//���ٳ���

void initWithString(MyString *string, char *copyString) {

    int length = strlen(copyString);//��ȡ�ַ�������
    string->reallyLength = length;//��ʼ���ַ�������
    string->pointer = (char *) calloc(length + 1, sizeof(char));// �����ڴ�
    stringCopy(string->pointer, copyString);//�����ַ���
}//��ʼ���������ַ���

//β�������ַ�
void backAddCharacter(MyString *string, char addCharacter) {

    if (strlen(string->pointer) + 1 == string->reallyLength) {
        //��ζ������
        string->pointer = realloc(string->pointer, string->reallyLength + 1);//���·����ڴ�

        string->reallyLength += 1;//ά��reallyLength

        string->pointer[string->reallyLength - 2] = addCharacter;
        string->pointer[string->reallyLength - 1] = '\0';
    } else {
        int currentLength = stringLength(string->pointer);
        string->pointer[currentLength] = addCharacter;
        string->pointer[currentLength + 1] = '\0';
    }

}

void backAddString(MyString *string, char *characterArray) {
    int nowStringLength = stringLength(string->pointer);//��ȡ��ǰ����
    int addStringLength = stringLength(characterArray);//Ҫ���ӵĳ���
    if (nowStringLength + addStringLength + 1 > string->reallyLength) {
        int needAddStringLength = nowStringLength + addStringLength + 1 - string->reallyLength;
        string->pointer = (char *) realloc(string->pointer, string->reallyLength + needAddStringLength);//�����ַ�������
        strcat(string->pointer, characterArray);//�����ַ���
        string->reallyLength += needAddStringLength;
    } else {
        strcat(string->pointer, characterArray);//�����ַ���
    }
}

void printString(MyString *string) {
    printf("\n%s", string->pointer);//��ӡ�ַ���
}

void run(MyString *string) {
    system(string->pointer);//ִ��ָ��
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
    char * pointer = findFirstCharacter(string->pointer,deleteCharacter);//����
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
    char * pointer = findStringFirstString(string,deleteString);//����
    if (pointer == NULL){
        return 0;
    } else{
      int length = strlen(deleteString);//���ַ�������
      char  * pointerNext = pointer + length;// ��һ���ַ�������
      while(*pointerNext != '\0'){
            *pointer = *pointerNext;
            pointer++;
            pointerNext++;
      }
      *pointer = '\0';//�ַ���Ҫ��β
      return 1;
    }
}

void addCharacter(MyString *myString,char character,char * position){
        if(position == NULL || myString == NULL)
            return ;
        if (stringLength(myString->pointer)+1 == myString->reallyLength){
            //��ζ������
            //���·����ڴ�
            myString->pointer = realloc(myString->pointer,myString->reallyLength+1);
            //ά��reallyLength
            myString->reallyLength+=1;
            int nowLength = stringLength(myString->pointer);
            int moveLength = stringLength(position);
            for (int i = nowLength; i > nowLength - moveLength ; i--) {
                myString->pointer[i] = myString->pointer[i-1];
            }
            myString->pointer[nowLength-moveLength] = character;//����
            myString->pointer[nowLength+1] = '\0';//�ַ�����β
        } else{
            int nowLength = stringLength(myString->pointer);//�����ǰ����
            int moveLength = stringLength(position);//Ҫ�ƶ��ĳ���
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
    int nowStringLength = stringLength(myString->pointer);//��ȡ��ǰ����
    int addStringLength = stringLength(string);//Ҫ���ӵĳ���
    if (nowStringLength + addStringLength + 1 > myString->reallyLength) {
        int needAddStringLength = nowStringLength + addStringLength + 1 - myString->reallyLength;
        myString->pointer = (char *) realloc(myString->pointer, myString->reallyLength + needAddStringLength);//�����ַ�������
        //�ƶ�������
        int nowLength = stringLength(myString->pointer);//�����ǰ����
        int moveLength = stringLength(position);//�������Ҫ�ƶ��ĳ���
        int insertLength = stringLength(string);
        for (int i = nowLength; i >= nowLength-moveLength ; i--) {

            myString->pointer[i+insertLength] = myString->pointer[i];
        }
        for (int i = 0; i < insertLength; ++i) {
           myString->pointer[nowLength-moveLength+i] = string[i];//��ֵ����

        }
        myString->reallyLength += needAddStringLength;
    } else {

        int nowLength = stringLength(myString->pointer);//�����ǰ����
        int moveLength = stringLength(position);//�������Ҫ�ƶ��ĳ���
        int insertLength = stringLength(string);
        for (int i = nowLength; i >= nowLength-moveLength ; i--) {

            myString->pointer[i+insertLength] = myString->pointer[i];
        }
        for (int i = 0; i < insertLength; ++i) {
            myString->pointer[nowLength-moveLength+i] = string[i];//��ֵ����
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