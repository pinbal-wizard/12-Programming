#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Remember to include stack.h in the same directory!


// Do not change anything in this struct definition
struct _stack {
	int data[100];
    int length;
};

// This function has already been done for you
// Read it carefully to give you an idea of how you
// might complete the rest of the implementation
stack create(void) {
    int size = 100;
	stack s = malloc(sizeof(struct _stack));
	if (s == NULL)
		exit(-1);
    s->length = 0;
	return s;
}

// Complete all of the functions below

void destroy(stack inp) {
    while (!is_empty(inp))
    {
        pop(inp);
    }
    free(inp->data);
    free(&(inp->length));
    free(inp);
}

void empty(stack inp) {
	while (!is_empty(inp))
    {
        pop(inp);
    }
}

int is_empty(stack inp) {
	if(inp->length == 0){
        return 1;
    }
    return 0;
}

void push(stack inp, int val) {
    inp->data[inp->length] = val;
    inp->length += 1;
}

int pop(stack inp) {
    inp->length -= 1;
    int val = *(inp->data + inp->length);
    return val;
}

// You can test your stack by using this main() function
int main() {
	stack s = create();
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
