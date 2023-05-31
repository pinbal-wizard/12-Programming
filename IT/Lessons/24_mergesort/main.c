#include <stdio.h>

// Function to merge two sorted subarrays
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Function to perform mergesort
void mergeSort(int arr[], int size) {
    if (size <= 1)
        return;

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    // Divide the array into two halves
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // Recursively sort the two halves
    mergeSort(left, mid);
    mergeSort(right, size - mid);

    // Merge the sorted halves
    merge(arr, left, mid, right, size - mid);
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Example usage
int main() {
    int arr[] = {9, 5, 2, 8, 1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    mergeSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}