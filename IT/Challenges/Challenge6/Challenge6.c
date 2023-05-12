#include <stdio.h>
#include "LinkedList.h"


void listPartition(LinkedList **list, int x){
    LinkedList *prev = NULL;
    LinkedList *current = *list;
    LinkedList *pivot = NULL;
    while (current->next != NULL)
    {
        if((int)current->val <= x){
            if(pivot == NULL){
                printf("Pivot Found \n");
                pivot = current;
                continue;
            }
            continue;
        }







        prev = current;
        current = current->next;
    }
    
}

int main(void) {
    LinkedList list = {(void*)10, NULL};
    for(int i = 10; i > 0; --i){
        append(&list, (void*)i);
    }
    printValues(&list, Int);
    //listPartition(**list, 5);
    printValues(&list, Int);
}
