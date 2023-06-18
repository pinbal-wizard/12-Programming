/*
	Write your implementation on the provided *.c file.
	Be prepared to submit this file as part of your response to Item 4 before the deadline.

	A basic test program is provided for you to check your code, but you should
	add to the tests if you feel they do not go far enough. During marking,
	your ADT will be marked with a more extensive testing program. Your code
	will also be read manually for aspects such as coding style.
*/

/*
	Description of ADT:
	A double-ended queue, often abbreviated as deque, is an abstract data type that allows
	insertion and deletion of elements at both ends of the queue. It combines the features of
	a stack (Last-In-First-Out) and a queue (First-In-First-Out), providing efficient operations
	for adding or removing elements from either end.

	Advice:
	There are a few methods to implement here, but all should (mostly) rely on your knowledge of stacks/queues.

	Requirements:
	You are to use an array to store the elements within this data structure.
	The size variable should keep track of the number of elements in the queue.
*/

// Define the maximum number of elements in the deque
#define MAX_ELEMENTS 100

// Define the Deque structure
typedef struct {
	int elements[MAX_ELEMENTS];
	int front;
	int rear;
	int size;
} Deque;

// Function to initialize a new deque
void initialize(Deque* deque);

// Function to check if the deque is empty
int isEmpty(const Deque* deque);

// Function to check if the deque is full
int isFull(const Deque* deque);

// Function to insert an element at the front of the deque
void enqueueFront(Deque* deque, int element);

// Function to insert an element at the rear of the deque
void enqueueRear(Deque* deque, int element);

// Function to remove and return the element from the front of the deque
int dequeueFront(Deque* deque);

// Function to remove and return the element from the rear of the deque
int dequeueRear(Deque* deque);

// Function to return the element at the front of the deque without removing it
int front(const Deque* deque);

// Function to return the element at the rear of the deque without removing it
int rear(const Deque* deque);

// Function to return the number of elements in the deque
int size(const Deque* deque);

// Function to print the elements of the deque
void printDeque(const Deque* deque);