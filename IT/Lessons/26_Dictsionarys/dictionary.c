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
    // TODO!
}

// daniel
int isFull(Dictionary *dict) {
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
    // TODO!
    // Return the index of the key if it is found
    return -1; // Key not found
}

// Daniel
void deleteEntry(Dictionary *dict, int key) {
    // TODO!
    // If an entry in the middle is deleted, heal the array
    // Remember to update the size property of the dictionary if something was deleted
}

// Function to display all key-value pairs in the dictionary
void display(Dictionary *dict) {
    int i = 0;
    while (i <= dict->size-1)
    {
        printf(" %i with value %i \n",dict->entries[i].key,dict->entries[i].value);
        i++;
    }
}

// Function to free the memory allocated for the dictionary
void destroy(Dictionary *dict) {
    // TODO!
}



void main(){
    Dictionary* dict = create(10);
    addEntry(dict, 0,5);
    addEntry(dict, 1,5);
    addEntry(dict, 2,5);
    addEntry(dict, 3,5);
    addEntry(dict, 4,5);
    addEntry(dict, 9,55);

    display(dict);
}