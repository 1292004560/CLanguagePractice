#include <stdio.h>
#include <stdlib.h>
#include "../Header/LinkedList.h"

void main(void) {


    ST *head = NULL;
    add(&head, 1, 79);
    add(&head, 3, 89);
    add(&head, 3, 90);
    //  printf("%f,%d\n",head->score,head->number);
    printf("����֮ǰ\n");

    showAll(head);
    printf("����֮��\n");
    head = addLast(head,1,4,4.5);
    showAll(head);
    return;
}
