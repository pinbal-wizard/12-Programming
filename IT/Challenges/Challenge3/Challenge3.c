#include <stdio.h>

void insertString(char text[], char str[], int position){
    int textLen = 0, strLen = 0; 
    while (text[textLen] != '\0')
    {
        ++textLen;
    }
    while (str[strLen] != '\0')
    {
        ++strLen;
    }

    int j = 0;
    char out[50];    

    for (int i = 0; i < textLen; i++)
    {
        if(i == position){
            for (j = 0; j < strLen; j++)
            {
                out[i+j] = str[j];
            }
        }
        out[i+j] = text[i];
    }

    for (int i = 0; i < textLen; i++) {     
        text[i] = out[i];     
    }      
    return;
}

int main(void) {
    char arr[] = {"The wrong sonson"};
    char arr2[] = {"per"};

    insertString(arr,arr2,20);
    int i = 0;

    printf("%s \n", arr);    
}

