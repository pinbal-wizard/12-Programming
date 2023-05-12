#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Remember to include stack.h in the same directory!

// Do not change anything in this struct definition
struct node {
	int data;
	struct node *next;
};

// Do not change anything in this struct definition
struct _stack {
	struct node *top;
};

// This function has already been done for you
// Read it carefully to give you an idea of how you
// might complete the rest of the implementation
stack create(void) {
	stack s = malloc(sizeof(struct _stack));
	if (s == NULL)
		exit(1);
	s->top = NULL;
	return s;
}

// Complete all of the functions below

void destroy(stack inp) {
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

void empty(stack inp) {
	while (!is_empty(inp))
    {
        pop(inp);
    }
}

int is_empty(stack inp) {
	if(inp->top == NULL){
        return 1;
    }
    return 0;
}

void push(stack inp, int val) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = inp->top == NULL ? NULL : inp->top;
    inp->top = newNode;
}

int pop(stack inp) {
    if(inp->top == NULL){
        printf("Cant pop empty stack");
        exit(1);
    }
    struct node* popNode = inp->top;
    int val = popNode->data;
    inp->top = popNode->next;
    free(popNode);
    return val;
}

// You can test your stack by using this main() function
int main() {
	stack s = create();
    printf("%p \n",&s->top);
    printf("%s",is_empty(s) ? "Empty \n" : "Not Empty \n");
    push(s,12);
    printf("%s",is_empty(s) ? "Empty \n" : "Not Empty \n");
    printf("popped %i \n",pop(s));
    printf("%s",is_empty(s) ? "Empty \n" : "Not Empty \n");
    push(s,12);
    push(s,11);
    push(s,1);
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
