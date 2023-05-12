#include <stdio.h>
#include <math.h>

int main(void){
    printf("enter number: ");
    long int input = 0;
    scanf("%li",&input); //assumed always a number

    //in class solution doesnt work
    //printf("%i \n",input % 10);
    //printf("%i",((input / 10) % 10));
    //printf("%i",((input / 100) % 10));

    /*for(int i = 1; i > input; i* 10){
        printf("%i",(input / i) % 10);
    }*/
    
    //working solution
    while (input != 0){
        printf("%i",input % 10);
        input /= 10;
    }
}