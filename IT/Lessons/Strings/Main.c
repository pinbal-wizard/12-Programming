#include <stdio.h>

int main(void) {
    char input[81];
    {
    char c = getchar();
    int i = 0;
    while (c != '\n'){
        input[i] = c;
        c = getchar();
        ++i; 
    }
    input[i] = '\0';
    printf("%s", input);
    }

    
}
