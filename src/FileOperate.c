#include <stdio.h>
#include <stdlib.h>

int main(void) {

    FILE *filePointer = fopen("E:\\a.txt", "r");
    int buffer = fgetc(filePointer);
    printf("%d",buffer);
    fclose(filePointer);
    return 0;
}

