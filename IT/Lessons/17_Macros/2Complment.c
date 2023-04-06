#include <stdio.h>
#include <stdlib.h>


void bitRepesentation(unsigned int input){
    int arr[16];
        for(int i = 16; i > 0; i--){
        arr[i-1] = input & 1;
        input = input >> 1;
    }
    for(int i =0; i < 16; ++i){
        printf("%i",arr[i] & 1);
    }
    
}


void twoComplement(int input){
    int absInput = abs(input) -1;
    int absArr[16];
    for(int i = 16; i > 0; i--){
        absArr[i-1] = input & 1;
        absArr[i-1] = absArr[i-1] * -1;
        input = input >> 1;
    }

    for(int i =0; i < 16; ++i){
        printf("%i",absArr[i] & 1);
    }
    printf("\n");
}

int main(void) {
    //bitRepesentation(100);
    twoComplement(100);
    twoComplement(-100);
}