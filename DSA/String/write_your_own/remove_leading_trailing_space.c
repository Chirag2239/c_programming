#include <stdio.h>
#include <ctype.h>
#include <string.h>

void trim_whitespace(char *str) {
    // Check for NULL or empty string
    if (str == NULL || *str == '\0') {
        return;
    }

    // Remove leading whitespace
    char *start = str;
    while (*start && isspace((unsigned char)*start)) {
        start++;
    }

    // If the string is all whitespace
    if (*start == '\0') {
        *str = '\0';
        return;
    }

    // Remove trailing whitespace
    char *end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) {
        end--;
    }

    // Null terminate the trimmed string
    *(end + 1) = '\0';

    // Move the trimmed string to the beginning
    memmove(str, start, end - start + 2);
}

int main() {
    char str[] = "   Hello, World!   ";
    printf("Original: '%s'\n", str);
    trim_whitespace(str);
    printf("Trimmed: '%s'\n", str);
    return 0;
}
