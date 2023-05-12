#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

// Remember to include stack.h in the same directory!

// Do not change anything in this struct definition
struct node {
	int data;
	struct node *next;
};

// Do not change anything in this struct definition
struct _queue {
	struct node *top;
};

// This function has already been done for you
// Read it carefully to give you an idea of how you
// might complete the rest of the implementation
queue create(void) {
	queue s = malloc(sizeof(struct _queue));
	if (s == NULL)
		assert("Error making queue");
	s->top = NULL;
	return s;
}

// Complete all of the functions below

void destroy(queue inp) {
    while (!is_empty(inp))
    {
        struct node* listPointer = inp->top;
        struct node* listPrev = inp->top;
        while (listPointer->next != NULL)
        {
            listPrev = listPointer;
            listPointer = listPointer->next;
        }
        free(listPointer);
        listPrev->next = NULL;
        if(inp->top == listPointer){
            inp->top = NULL;
        }
    }
    free(inp);
}

void empty(queue inp) {
	while (!is_empty(inp))
    {
        pop(inp);
    }
}

int is_empty(queue inp) {
	if(inp->top == NULL){
        return 1;
    }
    return 0;
}

void push(queue inp, int val) {
    printf("Push %i\n",val);
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    //printf(inp->top == NULL ? "top is Null\n":"top is %i\n",inp->top );
    struct node* listPointer;
    if(inp->top == NULL){
        inp->top = newNode;
        //printf(inp->top == NULL ? "top is Null\n":"top is %i\n",inp->top );
        return;
    }
    listPointer = inp->top;
    while (listPointer->next != NULL)
    {
        listPointer = listPointer->next;
    }
    listPointer->next = newNode;
}

int pop(queue inp) {
    assert(!is_empty(inp));
    
    struct node* popNode = inp->top;
    int val = popNode->data;
    inp->top = popNode->next;
    free(popNode);
    return val;
}

int peek(queue inp){
    return inp->top->data;
}

// You can test your stack by using this main() function
int main() {
	queue s = create();
    printf("%s",is_empty(s) ? "Empty \n" : "Not Empty \n");
    push(s,12);
    printf("%s",is_empty(s) ? "Empty \n" : "Not Empty \n");
    printf("popped %i \n",pop(s));
    printf("%s",is_empty(s) ? "Empty \n" : "Not Empty \n");
    push(s,12);
    push(s,11);
    push(s,1);
    printf("peek %i \n",peek(s));
    printf("popped %i \n",pop(s));
    printf("popped %i \n",pop(s));
    printf("popped %i \n",pop(s));
    printf("popped %i \n",pop(s));
    printf("popped %i \n",pop(s));
    push(s,12);
    empty(s);
    printf("%s",is_empty(s) ? "Empty \n" : "Not Empty \n");
    push(s,12);
    push(s,12);
    push(s,12);
    destroy(s);
    printf("popped %i \n",pop(s));
}
