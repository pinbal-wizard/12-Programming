#include <stdio.h>



void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(arr[j+1] < arr[j]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    } 
}

void selectionSort(int arr[], int n) {
    for(int i = 0;i < n; i++ ){
        int minValue = __INT_MAX__;
        int minPlace;
        for(int j = i; j < n; j++){
            if(arr[j] <= minValue){
                minValue = arr[j];
                minPlace = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minPlace];
        arr[minPlace] = temp; 
    }
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {17, 12, 11, 13, 5, 6 ,13,14};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    insertionSort(arr, n);
    //bubbleSort(arr, n);
    //selectionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}