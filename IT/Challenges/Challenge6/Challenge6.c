#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


void listPartition(LinkedList *list, int x){
    LinkedList *current = list;
    
    LinkedList *pivot = malloc(sizeof(LinkedList));
    pivot->next = NULL;
    pivot->val = NULL;
    LinkedList *head = malloc(sizeof(LinkedList));
    head->next = NULL;
    head->val = NULL;

    while (current->next != NULL)
    {
        if(current->val < (void*)x){
            head->val == NULL ? head->val = (void*)current->val: append(head,(void*)current->val);
        }     
        else{
            pivot->val == NULL ? pivot->val = (void*)current->val: append(pivot,(void*)current->val);
        }   
        current = current->next;
    }
    //appendList(head,pivot);
    printValues(&pivot,Int);
    printf("----------------------\n");
    printValues(&head,Int);
}

int main(void) {
    LinkedList list = {(void*)11, NULL};
    for(int i = 10; i > 0; --i){
        append(&list, (void*)i);
    }
    printValues(&list,Int);
    printf("----------------------\n");
    listPartition(&list, 5);
}
