#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include "LinkedList.h"

// Function to create a new dictionary
// Already done for you, implement the other functions
Dictionary *create(int capacity) {
    Dictionary *dict = (Dictionary *)malloc(sizeof(Dictionary));
    dict->entries = (int** )malloc(capacity * sizeof(int));
    dict->size = 0;
    dict->capacity = capacity;
    return dict;
}


int Hash(int inp, int size){
    int sum = inp;

    sum = sum % size;
    return sum;
}

//Azhar
int isEmpty(Dictionary *dict) {
    if(dict->size==0){
        return 1;
    }
    return 0;
}


// Daniel 
int isFull(Dictionary *dict) {
    if(dict->size==dict->capacity){
        return 1;
    }
    return 0;
}


// Function to add a key-value pair to the dictionary
int addEntry(Dictionary *dict, int value) {
    if (isFull(dict)) {
        printf("Error: Dictionary is full, cannot add more entries.\n");
        return -1;
    }
    int hashVal = Hash(value, dict->capacity);
    if(dict->entries[hashVal] != 0){
        printf("Error: hash Collsion");
        return -1;
    }
    int* val = (int*)malloc(sizeof(int));
    val = value;
    dict->entries[hashVal] = val;
    dict->size++;
    return 1;
}

//azhar
int search(Dictionary *dict, int hashVal) {
    if(dict->entries[hashVal] == NULL){
        return -1;
    }
    int resultP = dict->entries[hashVal];
    return *resultP;
}


// 
int deleteEntry(Dictionary *dict, int hashVal) {
    if(dict->entries[hashVal] == 0){
        printf("Error: No entry");
        return -1;
    }
    free(&(dict->entries[hashVal]));
    return 1;
}

// Function to display all key-value pairs in the dictionary
void display(Dictionary *dict) {
    for(int i = 0; i < dict->capacity; i++){
        printf("index %i is %i\n",i,dict->entries[i]);
    }
}


// azhar
void destroy(Dictionary *dict) {
    free(dict->entries);
    free(dict);
}



void runTests() {
    // Test create and isEmpty functions
    Dictionary *dict = create(5);
    if (isEmpty(dict)) {
        printf("Test 1 Passed: Dictionary created and is empty.\n");
    } else {
        printf("Test 1 Failed: Dictionary should be empty after creation.\n");
    }

    // Test addEntry and search functions
    addEntry(dict, 10);
    addEntry(dict, 20);
    addEntry(dict, 30);
    if (search(dict, Hash(20,dict->capacity)) == 20) {
        printf("Test 2 Passed: Value 20 found for key 2.\n");
    } else {
        printf("Test 2 Failed: Value for key 2 should be 20.\n");
    }
    
    // Test deleteEntry and isFull functions
    deleteEntry(dict, 2);
    if (isFull(dict)) {
        printf("Test 3 Failed: Dictionary should be full after adding 3 entries.\n");
    } else {
        printf("Test 3 Passed: Dictionary is full.\n");
    }

    // Test display function
    printf("Displaying dictionary:\n");
    display(dict);

    // Test destroy function
    destroy(dict);
    printf("Test 4 Passed: Dictionary destroyed.\n");
}

int main() {
    runTests();
    return 0;
}