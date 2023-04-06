#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

#include <stdio.h>
#include "source.h"

int main(void) {
    printf("%i",add(1,2));
    printf("%i",MIN(1,2));
}