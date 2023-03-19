#include <stdio.h>

#define MAX_LEN 100

// Function to find length of a string
int strLength(char *str) {
    int len = 0;
    while (*str != '\0') {
        len++;
        str++;
    }
    return len;
}

// Function to sort a string
void sortString(char *str) {
    int len = strLength(str);
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str1[MAX_LEN], str2[MAX_LEN];
    int len1 = 0, len2 = 0, i;

    printf("Enter first string: ");
    fgets(str1, MAX_LEN, stdin);
    str1[strLength(str1) - 1] = '\0'; // Remove newline character from input

    printf("Enter second string: ");
    fgets(str2, MAX_LEN, stdin);
    str2[strLength(str2) - 1] = '\0'; // Remove newline character from input

    // Find length of strings
    while (str1[len1] != '\0') {
        len1++;
    }
    while (str2[len2] != '\0') {
        len2++;
    }

    // Check if the length of the two strings is equal
    if (len1 != len2) {
        printf("The two strings are not permutations of each other.\n");
        return 0;
    }

    // Sort both strings
    sortString(str1);
    sortString(str2);

    // Compare sorted strings
    for (i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            printf("The two strings are not permutations of each other.\n");
            return 0;
        }
    }

    printf("The two strings are permutations of each other.\n");

    return 0;
}
