#include <stdio.h>
#include "../Lessons/Pointers/LinkedList.h"


void listPartition(LinkedList list, int x){

}

int main(void) {
    LinkedList list = {(void*)10, NULL};
    for(int i = 0; i < 10; ++i){
        append(&list, (void*)i);
    }
    printValues(&list, LList);
}
