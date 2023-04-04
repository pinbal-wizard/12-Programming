#include <stdio.h>


int bitpatternSearch(unsigned int search, unsigned int pattern, unsigned int n){
    int arr[16];
    for(int i = 16; i > 0; i--){
        printf("%i ",i);
        printf("%i",search & 1);
        arr[i-1] = search & 1;
        search = search >> 1;
        printf("\n");
    }

    printf("\n\n\n\n\n\n\n\n");
    for(int i = 0;i < 16; i++){
        printf("%i ",arr[i]);
    }
    printf("\n1 1 1 0 0 0 0 1 1 1 1 1 0 1 0 0");
    return 0;
}


int main(void) {
    bitpatternSearch(0xe1f4,0x5, 3);
    //printf("%i", 1 ); //1110 0001 1111 0100 //101 //3 // should return 11
}                     //0010 1111 1000 0111 0


