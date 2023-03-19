#include <stdio.h>
//hcf or gcd 
int main() {
    // x and y will never be negative for this program
    int x = 12;
    int y = 8;
    int temp;
    while( y != 0 ) { //while not 0         
        temp = x % y; //temp equals remainder of x / y          temp=100
        x = y; //x equals remainder of x/y  x= 500
        y = temp; // y equals remainder of x/y   y=100
    }
    printf("The answer is %i\n", x);
    return 0;
}



/*
temp = 100, x = 100, y = 500
temp = 100, x = 500, y = 500
temp = 100, x = 500, y = 100

temp = 0, x = 500, y = 0
y = 0


temp = 0, x = 78, y = 
*/