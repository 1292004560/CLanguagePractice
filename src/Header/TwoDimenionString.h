#ifndef PRACTISE_TWODIMENIONSTRING_H
#define PRACTISE_TWODIMENIONSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//字符串封装  库函数
struct String{
    char * pointer;//保存字符串的首地址
    int reallyLength;//字符串的实际长度

};

typedef struct String MyString;//简写

//字符串，初始化，打印，增加(字符，字符串)，删除(字符串，字符)
//查找，查找字符串，查找字符
//修改字符串，(字符串替换)
//尾部增加字符串，任意位置增加字符串(字符，字符串)
void init(MyString *string);//原封不动初始化

void initWithLength(MyString * string,int length);//开辟长度

void initWithString(MyString *string,char * copyString);//初始化并拷贝字符串

void printString(MyString *string);

void backAddCharacter(MyString *string,char c);//尾部增加字符

void backAddString(MyString *string,char *characterArray);

void run(MyString *string);

char * findStringFirstCharacter(MyString * string,char character);


char * findStringFirstString(MyString *string,char * findString);//返回第一个找到的字符串地址

int deleteFirstCharacter(MyString *string,char deleteCharacter);

int deleteFirstString(MyString *string,char * deleteString);


void addCharacter(MyString *string,char character,char *position);//任意位置增加字符

void addString(MyString *myString,char * string,char * position);//任意位置增加字符串

void changeFirstCharacter(MyString *myString, const char oldCharacter, const char newCharacter);//改变字符

void changeFirstString(MyString *myString, char *const oldString,char *const newString);//改变字符串


#endif //PRACTISE_TWODIMENIONSTRING_H
