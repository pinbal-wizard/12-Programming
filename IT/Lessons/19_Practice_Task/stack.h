typedef struct _stack *stack;

stack create(void);
void destroy(stack);
void empty(stack);
int is_empty(stack);
void push(stack, int);
int pop(stack);

// Note that this ADT would normally have an is_full() function
// But we will not specify a maximum size for our stack, for now
// So this would make an is_full() function redundant