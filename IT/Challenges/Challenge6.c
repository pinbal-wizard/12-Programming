#include <stdio.h>
#include "LinkedList.h"


void listPartition(LinkedList *list, int x){
    LinkedList *prev = NULL;
    LinkedList *head = list;
    while (head->next != NULL)
    {
        if(head->val >=){

        }
        prev = head;
        head = head->next;
    }
    
}

int main(void) {
    LinkedList list = {(void*)10, NULL};
    for(int i = 0; i < 10; ++i){
        append(&list, (void*)i);
    }
    printValues(&list, LList);
}
