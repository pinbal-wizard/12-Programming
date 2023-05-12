#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"

int factorial(int count){
    int sum = 1;
    for(int i = count; i > 0; i--){
        sum = sum * i;
    }
    printf("%i \n",sum);
}

int fibbinacciRecurse(int firstInt, int secondInt, int count){
    if (count <= 2){
        return secondInt + firstInt;
    }
    return fibbinacciRecurse(secondInt,firstInt + secondInt, --count);
}

int oddSum(int sum, int count){
    if(count <= 1){
        return sum;
    }
    return oddSum(sum * ( ( count * 2 ) + 1),--count);
}

int palindromeRecurse(char* inp){
    if(inp[0] != inp[strlen(inp)-1]){
        return 0;
    }
    if(strlen(inp) <= 3){
        return 1;
    }
    char* outp = malloc(8 * strlen(inp-2));
    strncpy(outp,(inp + 1),strlen(inp)-2);
    int out = palindromeRecurse(outp);
    free(outp);
    return out;
}

int main(void) {
    factorial(10);
    printf("%i\n",fibbinacciRecurse(0,1,14));
    printf("%i\n",oddSum(1,10));
    printf("%s",palindromeRecurse("racecars") ? "Palindrome\n":"Not Palindrome\n");
    printf("%s",palindromeRecurse("racecar") ? "Palindrome\n":"Not Palindrome\n");

    LinkedList head = {(void*)10, NULL};
    for (int i = 0; i < 10; ++i){
        append(&head, (void*)(i*3));
    }

    printf("%i",count(&head));
    printValues(&head,Int);
}


//-----------------LinkedList.h---------------
// int count(LinkedList *head){
//     int count = 1;
//     while(head->next != NULL){
//         count += 1;
//         head = head->next;
//     }
//     return count;
// }
