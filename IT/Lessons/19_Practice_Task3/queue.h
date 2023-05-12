typedef struct _queue *queue;

queue create(void);
void destroy(queue);
void empty(queue);
int is_empty(queue);
void push(queue, int);
int pop(queue);

// Note that this ADT would normally have an is_full() function
// But we will not specify a maximum size for our stack, for now
// So this would make an is_full() function redundant