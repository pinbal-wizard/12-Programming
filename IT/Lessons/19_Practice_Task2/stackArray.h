typedef struct _stack *stack;

stack create(void);
void destroy(stack inp);
void empty(stack inp);
int is_empty(stack inp);
void push(stack inp, int);
int pop(stack inp);

// Note that this ADT would normally have an is_full() function
// But we will not specify a maximum size for our stack, for now
// So this would make an is_full() function redundant