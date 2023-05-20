#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


void listPartition(LinkedList **list, int x){
    LinkedList *current = *list;
    
    LinkedList* pivotP = malloc(sizeof(LinkedList));
    pivotP->next = NULL;
    pivotP->val = NULL;
    LinkedList* headP = malloc(sizeof(LinkedList));
    headP->next = NULL;
    headP->val = NULL;
    LinkedList* tailP = malloc(sizeof(LinkedList));
    tailP->next = NULL;
    tailP->val = NULL;


    while (current != NULL)
    {
        if(current->val == (void*)x){
            pivotP->val == NULL ? pivotP->val = current->val : append(pivotP,(void*)current->val);
        }     
        else if(current->val < (void*)x){
            headP->val == NULL ? headP->val = current->val : append(headP,(void*)current->val);
        }     
        else{
            tailP->val == NULL ? tailP->val = current->val : append(tailP,(void*)current->val);
        }   
        current = current->next;
    }
    appendList(headP,pivotP);
    appendList(headP,tailP);
    **list = *headP;
}

int main(void) {
    LinkedList list = {(void*)10, NULL};
    LinkedList* listPointer = &list;
    for(int i = 9; i > 0; --i){
        append(&list, (void*)i);
    }
    append(&list, (void*)5);
    listPartition(&listPointer, 5);
    printValues(&list,Int);

    printf("\n");
    exit(0);
}
