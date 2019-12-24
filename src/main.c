#include "Header/TwoDimenionString.h"

void main(void) {

    MyString string;
    initWithString(&string, "notepad");
    printString(&string);
    //backAddCharacter(&string,'d');

    //backAddString(&string,"pad");
    //run(&string);

    //char *pointerString = findStringFirstCharacter(&string, 'a');
   // char * pointerString = findStringFirstString(&string,"ad");
   // *pointerString = 'A';
   //int i = deleteFirstCharacter(&string,'a');
  // int i = deleteFirstString(&string,"pad");

    char * pointer = findStringFirstCharacter(&string,'t');
    if (pointer != NULL){
        //addCharacter(&string,'A',pointer);
        addString(&string,"123",pointer);
    }

    printString(&string);
   // printf("%d",i);
    //printf("%s", string.pointer);

    printf("\n%d\n",string.reallyLength);
    free(&string);
    return;
}
