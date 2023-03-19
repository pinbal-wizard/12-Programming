#include <stdio.h>

void sort(char *input, int n){
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (input[i] > input[j]) {
                char temp = input[i];
                input[i] = input[j];
                input[j] = temp;
         }
      }
   }
}


int strlen(char* p){
    int count = 0;
    while (*p != '\0') {
        count++;
        p++;
    }
    return count;
}


int main(void){
    printf("Enter strings (100 max strings)");
    char inpa[50], inpb[50];
    printf("Enter first string: ");
    scanf("%s", inpa);

    printf("Enter second string: ");
    scanf("%s", inpb);

    if(strlen(inpa) != strlen(inpb)){
        printf("Wrong Length");
        return 1;
    }

    sort(&inpa, strlen(inpa));
    sort(&inpb, strlen(inpb));

    for(int i = 0; i < strlen(inpa); i++){
        if(inpa[i] != inpb[i]){
            printf("No permutation");
            return;
        }
    }    
    printf("Permutation!");
}


