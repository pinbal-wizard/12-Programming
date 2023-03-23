#include <stdio.h>

int main(void) {
    char arr1[] = {"dfsdhfsd"};
    char arr2[] = {"dfsdhfsd"};

    for (int i = 0; i < 8; ++i){
        if(arr1[i] != arr2[i]){
            printf("Not same");
            return;
        }
    }
    printf("same");
}
