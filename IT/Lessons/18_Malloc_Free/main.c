#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Simple string example

int main() {
    char *str = (char *) malloc(4);
    strcpy(str, "foo");
    printf("%s \n",str);
    free(str);
    printf("%s \n",str);
}