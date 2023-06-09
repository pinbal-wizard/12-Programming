#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

// Function to create a new dictionary
// Already done for you, implement the other functions
Dictionary *create(int capacity) {
    Dictionary *dict = (Dictionary *)malloc(sizeof(Dictionary));
    dict->entries = (KeyValuePair *)malloc(capacity * sizeof(KeyValuePair));
    dict->size = 0;
    dict->capacity = capacity;
    return dict;
}

//azhar
int isEmpty(Dictionary *dict) {
    if(dict->size==0){
        return 1;
    }
    return 0;
}


// daniel
int isFull(Dictionary *dict) {
    if(dict->size==dict->capacity-1){
        return 1;
    }
    return 0;
}


// Function to add a key-value pair to the dictionary
void addEntry(Dictionary *dict, int key, int value) {
    if (isFull(dict)) {
        printf("Error: Dictionary is full, cannot add more entries.\n");
        return;
    }
    KeyValuePair KeyValue = {key,value};
    dict->entries[dict->size] = KeyValue;
    dict->size++;
}

//azhar
int search(Dictionary *dict, int key) {
    for(int i = 0; i < dict->size;i++){
        if(dict->entries[i].key==key){
            return dict->entries[i].value;
        }
    }
    return -1; // Key not found
}


// 
int deleteEntry(Dictionary *dict, int key) {
        for(int i = 0; i < dict->size;i++){
        if(dict->entries[i].key==key){
            free(&(dict->entries[i]));
            return 1;
        }
    }
    return -1; // Key not found
}

// Function to display all key-value pairs in the dictionary
void display(Dictionary *dict) {
    for(int i = 0; i < dict->size; i++){
        printf("index %i is %i\n",dict->entries[i].key,dict->entries[i].value);
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
    addEntry(dict, 1, 10);
    addEntry(dict, 2, 20);
    addEntry(dict, 3, 30);
    if (search(dict, 2) == 20) {
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