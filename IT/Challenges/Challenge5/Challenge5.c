#include <stdio.h>
#include <stdlib.h>


int bitPatternSearch(unsigned int search, unsigned int pattern, unsigned int n){
    int arr[16];
    int *arr2 = malloc(sizeof(pattern));
    for(int i = 16; i > 0; i--){
        arr[i-1] = search & 1;
        search = search >> 1;
    }

    for(int i = n; i > 0; i--){
        arr2[i-1] = pattern & 1;
        pattern = pattern >> 1;
    }

    for(int i = 0; i < 16 - n; ++i){
        printf("%i\n",i);
        int cBits = 0;
        for(int j = 0;j < n; ++j){
            if(arr[i + j] == arr2[j]){
                printf("%i bit of arr is same as %i bit of arr2\n",i,j);
                ++cBits;
            }
            if(cBits == n){
                return i;
            }
        }
    }
    return -1;
}


int main(void) {
    printf("\n\n %i \n\n",bitPatternSearch(0xe1f4,0x5, 3));
    //printf("%i", 1 ); 1110 0001 1111 0100 ,101 ,3  should return 11
                      //0010 1111 1000 0111 0

    printf("insaity");
}




