#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myConcatenateString(char *dest,char *source,int size){

    if (dest == NULL || source == NULL)
        return;
    char * pointer = dest;
    while (*pointer != '\0')
        pointer++;
    //pointer指向了末端0
    for (int i = 0; i < size; ++i) {
        *pointer = source[i];
        pointer++;
    }
    *pointer = '\0';
}

void myReverseString(char * string){
    int length = strlen(string);
    for (int i = 0; i < length/2; ++i) {
        char templateCharacter = string[i];
        string[i] = string[length-i-1];
        string[length - i-1] = templateCharacter;
    }
}

void toUpper(char * string){
    while(*string != '\0'){
        if (*string >= 'a'&& *string<='z')
            *string = *string-32;
        string++;
    }
}

void toLower(char *string){
    while(*string != '\0'){
        if (*string > 'A'&& *string<'Z')
            *string = *string+32;
        string++;
    }
}

void main(void){

    char string[30] = "notepad";
    strupr(string);
    printf("%s\n",string);
    strlwr(string);
    printf("%s\n",string);
    toUpper(string);
    printf("%s\n",string);
    return;
}

void main3(void){

    char string[20] = "nihaozhoushuiping";
    printf("%s\n",string);
    //_strrev(string);
    myReverseString(string);
    printf("%s\n",string);
    return;
}

void main2(void){

    char string[100] = "88888";
    int number = atoi(string+1);
    printf("%d",number);
    //转换的时候，传递的是首地址，地址不要求是首地址
    //字符串任何地址都可以
    //转换成功就是整数，失败为0
    return;
}

void main1(void){

    char string[30] = "zhoushuiping";
    char string1[20] = "8848";
    strncat(string,string1,4);
    myConcatenateString(string,string1,4);
    printf("%s",string);
}


