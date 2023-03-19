#include <stdio.h>


int number(int count){
    if(count <= 0){
        return 0;
    }
    printf("%i \n",count);
    number(count - 1);
}

int factorial(int count, int sum){
    if(count <= 0){
        return sum;
    }
    sum *= count;
    printf("%i \n",sum);
    factorial(count - 1, sum);
}

int gcd(int x, int y) {
    if(y == 0){
        printf("The answer is %i\n", x);
        return 0;
    }
    int temp;       
    temp = x % y; 
    x = y; 
    y = temp; 

    gcd(x,y);
}

int main(void) {
    //factorial(10, 15);
    gcd(12,10);
}  