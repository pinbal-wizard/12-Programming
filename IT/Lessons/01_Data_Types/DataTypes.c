#include <stdio.h>
#include <math.h>

int math_func(void){
    float input;
    printf("Enter number: ");
    scanf("%f", &input);

    float output = 3 * powf(input,3) - 5 * powf(input,2) + 6;
    printf("%f",output);

    return 0;
}


int n_n_square(void){
    printf("________\n");
    for(int i = 1; i < 11; i++ ){
        printf(" %i | %li \n",i,i*i);
    }
    printf("--------\n");
    return 0;
} 

int factorial(int num){
    double j = 1;
    for (int i = 0; i < num + 1; i++)
    {
        printf("%i, %lf\n",i,j);
        j=j*(i+1);
    }
    return 0;
}


int triangle_number(int num){
    int j = 1;
    for(int i = 1; i< num + 1; i++){
        printf("%i ,%i \n",i,j);
        j+=i+1;
    }
    return 0;
}


int d_equals_d(void)
{
char c, d;
c = 'd';
d = c;
printf ("d = %c\n", d);
return 0;
}


int main(void){
    //d_equals_d();
    //math_func();
    //n_n_square();
    //factorial(13);
    triangle_number(13);
}