#include <stdio.h>
#include "LinkedList.h"

int main(void) {
    LinkedList *head = (LinkedList*) malloc(sizeof(LinkedList));
    char *input;
    printf("Start \n");
    gets(input);  
    while (input[0] != '\0')
    {
        printf("Appending");
        append(head, (void*)1);
        printf("Added %s \n", input);
        gets(input);
    }
    printf("Done\n");    
    printValues(head,Int);
}