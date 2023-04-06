#include "LinkedList.h"
#include <stdio.h>


int main(void) {  
    LinkedList doubleHead = {(void*)"Gamingskjfhkjsdfhfkudshfkjghdkjfhgukdhgkjdkjfghdjkfhgkjdfhgjkdhkjjkdshfkusdhifugsdhukfh", NULL};
    LinkedList head = {(void*)10, NULL};
    LinkedList charHead = {(void*)'N', NULL};

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


    LinkedList funnyHead = {&head};
    append(&funnyHead, &doubleHead);
    append(&funnyHead, &charHead);

    
    printValues(&funnyHead, LList);
    
    int pointerToSecondArray = getValue(&funnyHead, 1);
    printf("%d \n",pointerToSecondArray);

    enum Type valType = String;
    printValues(pointerToSecondArray, String);
}