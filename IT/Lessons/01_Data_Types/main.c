#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    srand(time(NULL));  
    printf("Number between 1 and 10 \n");
    int guess = scanf("i fogor");
    
    int num = rand() % 10;
    if(guess == num)
    {
        printf("el cringe ");
    }
    else
    {
        printf("no ");
        printf("%i ",num);
    }
    return 0;
}