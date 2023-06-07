#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void main(){
    LinkedList* list  = createLinkedList((void*)10);

    printValues(list,Int);
    append(list, (void*)5);
    printValues(list,Int);

    int arr[] = {1,4,7,2,4,67};
    appendArray(list,arr,6);
    printValues(list,Int);

    printf("4 is at index %i\n",getIndex(list,4));
    printf("40 is at index %i\n",getIndex(list,40));

    printf("%i is at index 2\n",getValue(list,2));
    printf("%i is at index 20\n",getValue(list,20));

    LinkedList* list2  = createLinkedList((void*)10);
    for(int i = 0; i < 10; ++i){
        append(list2,(void*)(5*i));
    }
    printValues(list2,Int);
    appendList(list,list2); //append list is broken
    printValues(list,Int);
}