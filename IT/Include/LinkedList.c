#include <stdio.h>
#include <stdlib.h>

enum Type {String, Char, Int, Linkedlist, Pointer};

typedef struct node
{
    void* val;
    struct node* next;
}Node; 

typedef struct linkedList
{
    Node* data;
}LinkedList;


//create a linked list
LinkedList* createLinkedList(void* firstItem){
    LinkedList* list  = (LinkedList *)malloc(sizeof(LinkedList));
    Node* newNode = (Node *)malloc(sizeof(struct node));
    newNode->val = firstItem;
    newNode->next = NULL;
    list->data = newNode;
    return list;
}

//find index of a item in list -1 if not in
int getIndex(LinkedList* head, void* val){
    Node *current = head->data;
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
//returns value if found NULL if not
void* getValue(LinkedList *head, int index){
    Node *current = head->data;
    int i = 0;

    while (current != NULL && i != index) {
        current = current->next;
        i++;
    }

    if(current == NULL){
        return NULL;
    }
    return current->val;
}


//add a LinkedList(value) to the end of the list
int append(LinkedList *head,void* val){
    Node *LinkedListPointer = head->data;
    while (LinkedListPointer->next != NULL ) {
        //printf("LinkedList at %p contains ( %p , %d)\n",LinkedListPointer, LinkedListPointer->next, LinkedListPointer->val);
        LinkedListPointer = LinkedListPointer->next;
    }
    LinkedListPointer->next = (struct Node*) malloc(sizeof(Node));
    LinkedListPointer->next->val = val;
    LinkedListPointer->next->next = NULL;
    //printf("%p",LinkedListPointer);
    return 1;
}


//add an array to a LinkedList(value) to the end of the linkedList
int appendArray(LinkedList *head ,int values[],int valuesLength){
    Node *LinkedListPointer = head->data;
    while (LinkedListPointer->next != NULL ) {
        //printf("LinkedList at %p contains ( %p , %d)\n",LinkedListPointer, LinkedListPointer->next, LinkedListPointer->val);
        LinkedListPointer = LinkedListPointer->next;
    }
    
    for(int i = 0; i < valuesLength; i++){
        //printf("LinkedList at %p contains ( %p , %d)\n",LinkedListPointer, LinkedListPointer->next, LinkedListPointer->val);
        LinkedListPointer->next = (struct Node*) malloc(sizeof(Node));
        //printf("%i",values[i]);
        LinkedListPointer->next->val = (void*)values[i];
        LinkedListPointer->next->next = NULL;
        LinkedListPointer = LinkedListPointer->next;
    }

    //printf("%p",LinkedListPointer);
    return 1;
}


int appendList(LinkedList *dest, LinkedList *source){
    Node *destHead = dest->data;
    Node *sourceHead = dest->data;
    struct Node *linkedListPointer = dest;
    while (destHead->next != NULL)
    {
        destHead = destHead->next;
    }
    destHead->next = sourceHead;
    return -1;
}


//remove a LinkedList from the list based of value 
//returns 2 on head node removed and 1 on anyother removed
//-1 on no node removed
void removeNode(LinkedList *head, void* val) {
    Node *prev = NULL;
    Node *current = head->data;

    if(current->val == NULL){
        head->data = current->next;
        return 2;
    }

    while (current != NULL) {
        if (current->val == val) {
            prev->next = current->next;
            free(current); // free memory for the removed LinkedList
            return 1;
        }
        prev = current;
        current = current->next;
    }
    return -1;
}


//remove a LinkedList from the list based of index
//returns 1 on succesful removal
//returns -1 on index being out of list
int removeAt(LinkedList *head, int index) {
    Node *prev = NULL;
    Node *current = head->data;
    int i = 0;

    if(index == 0){
        head->data = current->next;
        return 1;
    }

    while(i != index & current != NULL){
        ++i;
        prev = current;
        current = current->next;
    }

    if(current == NULL){
        return -1;
    }

    prev->next = current->next;
    free(current);
    return 1;
}


//set a value at a certain index
int setValue(LinkedList *head, int index, void* newVal){
    Node *current = head->data;
    int i = 0;
    while(i != index && current != NULL){
        ++i;
        current = current->next;
    }
    current->val = newVal;
    return 1;
}



//sorts the list (uses a comparison)
int sortList(LinkedList *ListHead){
    Node *head = ListHead->data;
    Node *current = ListHead->data; 
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
    return 1;
}

//will remove all duplicate values from list
int removeDuplicates(LinkedList *head){
    Node *prev = NULL;
    Node *current = head->data;
    int prevIndexCount = 0;
    while (current != NULL)
    {
        if(current->val == prev->val){
            removeAt(head,prevIndexCount+1);
            current = prev->next;
            continue;
        }
        current = current->next;
        prev = prev->next;
        ++prevIndexCount;
    }
    return 1;
} 


void printValues(LinkedList *head, enum Type valType){
    Node* current = head->data;
    printf("-------inside list--------- \n");
    while (current != NULL) {
        switch (valType)
        {
        case String:
            printf("%s \n", current->val);
            break;
        case Char:
            printf("%c \n", current->val);
            break;
        case Int:
            printf("%d \n", current->val);
            break;
        case Linkedlist: 
            printValues(current->val,Pointer);
            break;
        case Pointer:
            printf("%p \n", current->val);
            break;
        default:
            printf("Incompatitble Type");
            break;
        }
        current = current->next;
    }
    printf("-------outside list--------- \n");
}


int count(LinkedList *head){
    Node* current = head->data; 
    int count = 1;
    while(current->next != NULL){
        count += 1;
        current = current->next;
    }
    return count;
}


