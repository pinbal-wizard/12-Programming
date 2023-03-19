// Build a simple dictionary in C by completing this code
#include <stdio.h>
#include <stdbool.h>

struct entry {
    char word[15];
    char definition[50];
};

// Implement this function!
// Did you already complete this function in the previous lesson practice set?
bool equalStrings(const char s1[], const char s2[]) {
    int x = 0;
    while (s1[x] != '\0' | s2[x] != '\0')
    {
        if(s1[x] != s2[x]){
            return false;
        }
        ++x;
    }
    return true;
}

// Implement this function!
// Note that the first argument is an array of struct entry
// This function should make use of equalStrings()
int lookup(const struct entry dictionary[], const char searchTerm[], const int entries) {
    for(int i = 0; i < entries; i++){
        if(equalStrings(searchTerm,dictionary[i].word)){
            return i;
        }
    }
    return -1;
}

// main() is complete
// study how an array of structures is initialized
// Perhaps you can add a few more entries to dictionary
int main() {
    const struct entry dictionary[100] = {
        { "abyss", "a bottomless pit" },
        { "acumen", "mentally sharp; keen" },
        { "addle", "to become confused" },
        { "affix", "to append; attach" },
        { "ajar", "partially opened" }
    };

    char word[10];
    int entries = 5;
    int entry;
    
    printf("Enter word: ");
    scanf("%14s", word);
    entry = lookup (dictionary, word, entries);
    
    if (entry != -1) {
        printf("%s\n", dictionary[entry].definition);
    } else {
        printf("Word not found!\n");
    }

    return 0;
}