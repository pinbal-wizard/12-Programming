#include <stdio.h>


int factorial(int count){
    int sum = 1;
    for(int i = count; i > 0; i--){
        sum = sum * i;
    }
    printf("%i \n",sum);
}


int main(void) {
    factorial(10);
}

