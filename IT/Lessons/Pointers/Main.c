#include "LinkedList.h"
#include <stdio.h>


int main(void) {  
    struct LinkedList doubleHead = {(void*)"Gamingskjfhkjsdfhfkudshfkjghdkjfhgukdhgkjdkjfghdjkfhgkjdfhgjkdhkjjkdshfkusdhifugsdhukfh", NULL};
    struct LinkedList head = {(void*)10, NULL};
    struct LinkedList charHead = {(void*)'N', NULL};

    for (int i = 0; i < 10; ++i){
        append(&head, (void*)(i*3));
    }
    for (int i = 0; i < 10; ++i){
        append(&charHead, (void*)(i+65));
    }
    char funny[] = "sdfoiysdiufsudsdjkhfksdgujfhjgdhgdsguyfasguyudgsdfyugsduygyudhguygdsfuyyguehuigvhsduyfhguiyesdguygdsuyfgyusdgfghvjdsfgvjsdfjgvjhsdfhjvgsdjkghjsdghfdjghdsfjhgfuydsguysdfuygusydfguysduyfghudfgdfyugdsfuyguydfuisdiufguis1";
    for (int i = 0; i < 10; ++i){
        append(&doubleHead, (void*)(funny));
    }
    append(&head, (void*)(25));


    struct LinkedList funnyHead = {&head};
    append(&funnyHead, &doubleHead);
    append(&funnyHead, &charHead);

    
    printValues(&funnyHead, LinkedList);
    
    int pointerToSecondArray = getValue(&funnyHead, 1);
    printf("%d \n",pointerToSecondArray);

    enum Type valType = String;
    printValues(pointerToSecondArray, String);
}