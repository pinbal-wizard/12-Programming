#include <stdio.h>

int main(void){
    float val1, val2;
    char operator;

    printf("enter math i.e. 4 + 4 : ");
    scanf("%f %c %f", &val1, &operator, &val2);

    switch (operator)
    {
    case '+':
        printf("%f",val1 + val2);
        break;
    case '-':
        printf("%f", val1 - val2);
        break;
    case '*':
        printf("%f", val1 * val2);
        break;
    case '/':
        if(val2 = '0'){
            printf("Divide By 0");
            break;
        }
        printf("%f",val1 / val2);
        break;
    
    default:
        break;
    }
    return 1;
} 