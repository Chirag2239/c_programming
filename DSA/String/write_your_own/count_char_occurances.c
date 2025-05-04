#include <stdio.h>

// Function to count occurrences of a character in a string
int count_char_occurrences(const char *str, char ch) {
    int count = 0;
    
    // Iterate through the string until the null terminator
    while (*str) {
        if (*str == ch) {
            count++;
        }
        str++;
    }
    
    return count;
}

int main() {
    const char *string = "hello world";
    char character = 'o';
    
    int occurrences = count_char_occurrences(string, character);
    printf("The character '%c' occurs %d times in the string \"%s\".\n", character, occurrences, string);
    
    return 0;
}
