#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to preprocess the string: remove spaces and convert to lowercase
char* preprocess_string(const char *str) {
    int len = strlen(str);
    char *processed = (char*)malloc(len + 1);
    if (processed == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (!isspace((unsigned char)str[i])) {
            processed[j++] = tolower((unsigned char)str[i]);
        }
    }
    processed[j] = '\0';
    return processed;
}

bool ispalindrome(const char *str) {
    if (str == NULL || *str == '\0') {
        printf("str is not valid\n");
        return false;
    }
    
    char *processed_str = preprocess_string(str);
    int ssize = strlen(processed_str);
    
    for (int i = 0; i < ssize / 2; i++) {
        if (processed_str[i] != processed_str[ssize - i - 1]) {
            free(processed_str);
            return false;
        }
    }
    
    free(processed_str);
    return true;
}

int main() {
    char *str = "A man a plan a canal PanamA";
    bool status = ispalindrome(str);
    if (status) {
        printf("The string is a palindrome\n");
    } else {
        printf("The string is not a palindrome\n");
    }
    return 0;
}
