#include <stdio.h>

int min(int arr[10]){
    int min = 2147483647;

    for(int i = 0; i < 10; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }

    return min;
}

void sortList(int arr[10]){
    for (int step = 0; step < 10 - 1; ++step) {
        for (int i = 0; i < 10 - step - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];

                arr[i] = arr[i+1];
                arr[i + 1] = temp;
            }
        }
    }
    
    for(int i = 9; i >= 0; i--){
        printf("%i \n",arr[i]);
    }
}



int main(void){
    int arr[] = {1,4,6,43,5,8,6,3,1,-2};
    printf("%i", min(arr));

    printf("\n\n\n\n\n\n\n");

    sortList(arr);
}


