#include <stdio.h>
#include "LinkedList.h"

// Function to swap two elements
void swap(LinkedList* head,void* a, void* b) {
    void* temp = getValue(head, a);
    setValue(head, a,getValue(head, b));
    setValue(head, b, temp);
}

// Function to partition the array and return the pivot index
int partition(LinkedList* head, int low, int high) {
    int pivot = getValue(head,high);  // Select the last element as the pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to the pivot
        if (getValue(head,j) <= pivot) {
            i++;
            swap(head,i,j);
        }
    }
    swap(head,i + 1, high);
    return (i + 1);
}

// Function to implement Quicksort algorithm
void quicksort(LinkedList* head, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pivot = partition(head, low, high);

        // Recursively sort the sub-arrays
        quicksort(head, low, pivot - 1);
        quicksort(head, pivot + 1, high);
    }
   
}

// Example usage
int main() {
    LinkedList* list = createLinkedList(10);

    for(int i = 0;i < 10; i++ ){
        append(list,(i*3)%15);
    }
    int size = 11;

    printf("Original array: ");
    printValues(list, Int);

    quicksort(list, 0, size - 1);

    printf("Sorted array: ");
    printValues(list, Int);

    return 0;
}