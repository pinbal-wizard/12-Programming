// Struct for a key-value pair
typedef struct {
    int key;
    int value;
} KeyValuePair;

// Dictionary ADT
typedef struct {
    KeyValuePair *entries;
    int size;
    int capacity;
} Dictionary;

// Function to create a new dictionary
Dictionary *create(int capacity);

// Function to check if the dictionary is empty
int isEmpty(Dictionary *dict);

// Function to check if the dictionary is full
int isFull(Dictionary *dict);

// Function to add a key-value pair to the dictionary
void addEntry(Dictionary *dict, int key, int value);

// Function to search for a value given a key
int search(Dictionary *dict, int key);

// Function to delete an entry given a key
void deleteEntry(Dictionary *dict, int key);

// Function to display all key-value pairs in the dictionary
void display(Dictionary *dict);

// Function to free the memory allocated for the dictionary
void destroy(Dictionary *dict);