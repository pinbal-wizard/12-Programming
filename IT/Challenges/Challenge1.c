#include <stdio.h>

int main (void){
    printf("Enter a number: ");
    int input = 0;
    scanf("%i",&input);
    if(input <= 1){
        printf("Is not prime");
        return 0;
    }
    for(int i = 2; i < input; i++){
        if (input % i == 0){
            printf("Is not prime");
            return 0;
        }
    }
    printf("Is prime");
}


