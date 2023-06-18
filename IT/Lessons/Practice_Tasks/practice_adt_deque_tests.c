#include <stdio.h>
#include "practice_adt_deque.h"

// Function to run the unit tests
void runTests() {
    Deque deque;
    initialize(&deque);

    // Enqueue elements at the front
    enqueueFront(&deque, 10);
    enqueueFront(&deque, 20);
    enqueueFront(&deque, 30);

    // Enqueue elements at the rear
    enqueueRear(&deque, 40);
    enqueueRear(&deque, 50);

    // Print the deque
    printf("Deque after enqueue:\n");
    printDeque(&deque);

    // Dequeue elements from the front
    printf("Dequeued elements from the front:\n");
    while (!isEmpty(&deque)) {
        int element = dequeueFront(&deque);
        printf("%d ", element);
    }
    printf("\n");

    // Enqueue elements at the rear
    enqueueRear(&deque, 60);
    enqueueRear(&deque, 70);
    enqueueRear(&deque, 80);

    // Print the deque
    printf("Deque after enqueue and dequeue:\n");
    printDeque(&deque);

    // Access the front and rear elements
    printf("Front element: %d\n", front(&deque));
    printf("Rear element: %d\n", rear(&deque));

    // Check the size of the deque
    printf("Deque size: %d\n", size(&deque));

    // Dequeue elements from the rear
    printf("Dequeued elements from the rear:\n");
    while (!isEmpty(&deque)) {
        int element = dequeueRear(&deque);
        printf("%d ", element);
    }
    printf("\n");

    // Check if the deque is empty
    printf("Is the deque empty? %s\n", isEmpty(&deque) ? "Yes" : "No");
}

// Main function
int main() {
    // Run the unit tests
    runTests();

    return 0;
}
