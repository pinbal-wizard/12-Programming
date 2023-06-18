#include <stdio.h>
#include <stdlib.h>

/*
    This is a basic implementation of a stack.
    Read through the entire file carefully before making any changes.

    Your task is to modify the existing implementation to include a function
    that finds the minimum element in the stack without iterating through all of the elements
    nor using any additional data structures.

    Your function for the 'find minimum' operation must have the signature: int findMinimum(Stack* stack);
    This function has been placed next to the main method below and requires your implementation.

    This is a practice question. There is no need to submit your response to Google Classroom.
    Avoid the use of any inbuilt library code. Aim to write original code only.
*/

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    Node* min;
} Stack;

// Function to initialize the stack
void initialize(Stack* stack) {
    stack->top = NULL;
    stack->min = NULL;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(Stack* stack, int element) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed. Cannot push element.\n");
        return;
    }

    if(stack->min->data > element){
        stack->min = newNode;
    }

    newNode->data = element;
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop element.\n");
        return -1; // Error value
    }

    Node* temp = stack->top;
    int poppedElement = temp->data;
    stack->top = stack->top->next;

    if(&temp == &(stack->min)){
        printf("Warning:popped was min element"); 
        //this will crash if you try and acress smallest element after it has popped will crash THIS IS INTENDED BEHAVIOUR
        stack->min = NULL;
    }

    free(temp);
    return poppedElement;
}

// Function to get the top element of the stack without removing it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1; // Error value
    }

    return stack->top->data;
}

// Function to display the elements of the stack
void display(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    Node* current = stack->top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the stack
void freeStack(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    stack->top = NULL;
}

// Function that finds the minimum element in the stack
// This function must NOT iterate through the elements of the stack
int findMinimum(Stack* stack){
    return stack->min->data;
}

int main() {
    Stack stack;
    initialize(&stack);

    // Push elements onto the stack
    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 15);
    push(&stack, 20);

    // Display the elements of the stack
    display(&stack);

    // Pop an element from the stack
    int poppedElement = pop(&stack);
    printf("Popped element: %d\n", poppedElement);

    // Display the elements of the stack
    display(&stack);

    // Get the top element of the stack
    int topElement = peek(&stack);
    printf("Top element: %d\n", topElement);

    // Free the memory allocated for the stack
    freeStack(&stack);

    return 0;
}

