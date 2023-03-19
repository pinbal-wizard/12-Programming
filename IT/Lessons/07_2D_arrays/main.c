#include <stdio.h>

int main(void){
    int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };

    for(int x = 0; x < 2; x++){
        for(int y = 0; y < 3; y++){
            printf("%i ", matrix[x][y]);
        }
        printf("\n");
    }
}