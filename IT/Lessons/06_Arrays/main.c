#include <stdio.h>

void main(void){
    int num = 10;
    int output[10]; 
    //1,1 2   1,2 3   2,3 5
    int a = 0,b = 1;
    for(int j = 0; j < num; j++){
        int temp = a + b;
        output[j] = a;
        a = b;
        b = temp;
        output[j] = a;
    }
    for(int i = 0; i < num;i++){
        printf("%d \n",output[i]);
    }
}


