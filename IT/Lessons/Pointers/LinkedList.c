#include <stdio.h>
#include <stdlib.h>

enum Type {String, Char, Int, LinkedList};

struct LinkedList
{
    void* val;
    struct LinkedList *next;
}; 


//find index of a item in list -1 if not in
int getIndex(struct LinkedList *head, void* val){
    struct LinkedList *current = head;
    int i = 0;

    while (current != NULL && current->val != val) {
    current = current->next;
    i++;
    }

    if(current == NULL){
        return -1;
    }
    return i;
}


//find value at index
void* getValue(struct LinkedList *head, int index){
    struct LinkedList *current = head;
    int i = 0;

    while (current != NULL && i != index) {
        current = current->next;
        i++;
    }

    return current->val;
}


//add a LinkedList(value) to the end of the list
void append(struct LinkedList *LinkedListPointer,void* val){
    while (LinkedListPointer->next != NULL ) {
        //printf("LinkedList at %p contains ( %p , %d)\n",LinkedListPointer, LinkedListPointer->next, LinkedListPointer->val);
        LinkedListPointer = LinkedListPointer->next;
    }
    
    LinkedListPointer->next = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    LinkedListPointer->next->val = val;
    LinkedListPointer->next->next = NULL;
    //printf("%p",LinkedListPointer);
    return;
}


//add an array to a LinkedList(value) to the end of the linkedList
void appendArray(struct LinkedList *LinkedListPointer ,int values[],int valuesLength){
    while (LinkedListPointer->next != NULL ) {
        //printf("LinkedList at %p contains ( %p , %d)\n",LinkedListPointer, LinkedListPointer->next, LinkedListPointer->val);
        LinkedListPointer = LinkedListPointer->next;
    }
    
    for(int i = 0; i < valuesLength; i++){
        //printf("LinkedList at %p contains ( %p , %d)\n",LinkedListPointer, LinkedListPointer->next, LinkedListPointer->val);
        LinkedListPointer->next = (struct LinkedList*) malloc(sizeof(struct LinkedList));
        //printf("%i",values[i]);
        LinkedListPointer->next->val = (void*)values[i];
        LinkedListPointer->next->next = NULL;
        LinkedListPointer = LinkedListPointer->next;
    }

    //printf("%p",LinkedListPointer);
    return;
}


//remove a LinkedList from the list based of value
void removeNode(struct LinkedList **head, void* val) {
    struct LinkedList *prev = NULL;
    struct LinkedList *current = *head;

    while (current != NULL) {
        if (current->val == val) {
            if (prev == NULL) { // the LinkedList to be removed is the head LinkedList
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current); // free memory for the removed LinkedList
            return;
        }
        prev = current;
        current = current->next;
    }
}


//remove a LinkedList from the list based of index
void removeAt(struct LinkedList **head, int index) {
    struct LinkedList *prev = NULL;
    struct LinkedList *current = *head;
    int i = 0;

    while(i != index && current != NULL){
        ++i;
        prev = current;
        current = current->next;
    }

    if(current != NULL){
        if(prev != NULL){
            prev->next = current->next;
        }else{
            *head = current->next; // update the head pointer
        }
        free(current);
    }
}


//set a value at a certain index
void setValue(struct LinkedList *head, int index, void* newVal){
    struct LinkedList *current = head;
    int i = 0;
    while(i != index && current != NULL){
        ++i;
        current = current->next;
    }
    current->val = newVal;
}


//sorts the list (uses a comparison)
void sortList(struct LinkedList *head){
    //printf("sorting list");
    struct LinkedList *current = head; 
    int size = 0;
    while(current != NULL){
        size++;
        current = current->next;
    }

    for (int step = 0; step < size - 1; ++step) {
        for (int i = 0; i < size - step - 1; ++i) {
            if (getValue(head, i) > getValue(head, i+1)) {
                int temp = (int)getValue(head,i);

                setValue(head, i,getValue(head, i+1));
                setValue(head, i+1, (void*)temp);
            }
        }
    }
}

//will remove all duplicate values from list
void removeDuplicates(struct LinkedList *head){
    struct LinkedList *prev = head;
    struct LinkedList *current = head->next;
    int prevIndexCount = 0;
    while (current != NULL)
    {
        if(current->val == prev->val){
            removeAt(&head,prevIndexCount+1);
            current = prev->next;
            continue;
        }
        current = current->next;
        prev = prev->next;
        ++prevIndexCount;
    }
} 


void printValues(struct LinkedList *head, enum Type valType){
    while (head != NULL) {

        switch (valType)
        {
        case String:
            printf("%s \n", head->val);
            break;
        case Char:
            printf("%c \n", head->val);
            break;
        case Int:
            printf("%d \n", head->val);
            break;
        case LinkedList:
            printf("%p \n", head->val);
            break;
        default:
            printf("Incompatitble Type");
            break;
        }
        //printf("LinkedList at %p contains ( %p , %d)\n",head, head->next, head->val);
        head = head->next;
    }
}


