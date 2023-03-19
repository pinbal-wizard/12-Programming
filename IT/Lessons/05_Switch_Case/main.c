#include <stdio.h>

int main(void){
    char num[20];
    scanf("%s",num);

    int i = 0;
    while (num[i] != '\0')
    {
        int digit = num[i];

        switch (digit)
        {
        case '1':
            printf("one");
            break;
        case '2':
            printf("two");
            break;
        case '3':
            printf("three");
            break;
        case '4':
            printf("four");
            break;
        case '5':
            printf("five");
            break;
        case '6':
            printf("six");
            break;
        case '7':
            printf("seven");
            break;
        case '8':
            printf("eight");
            break;
        case '9':
            printf("nine");
            break;
        case '0':
            printf("zero");
            break;
        
        default:
            break;
        }

        i++;
    }
    
}
