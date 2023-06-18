/*
    This program is buggy and not working as intended. Find as many bugs as you can.
    Write a comment at the buggy line describing the problem (aim for: half a sentence; max: 1 sentence).
    Fix the bugs so that the program works as intended.

    Submit this source file to Google Classroom before deadline as part of your response.
    Only submit this file if you have made any changes.

    This is a practice question. There is no need to submit your response to Google Classroom.
    Avoid the use of any inbuilt library code. Aim to write original code only.
*/
#include <stdio.h>

// Function to perform insertion sort on an array
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i <= n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j] = key;
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = { 4, 2, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Array after sorting: ");
    printArray(arr, n);

    return 0;
}

