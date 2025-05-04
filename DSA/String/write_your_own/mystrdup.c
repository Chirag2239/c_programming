#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mystrdup(const char *str) {
    // Check for NULL or empty string
    if (str == NULL || *str == '\0') {
        printf("str is not valid\n");
        return NULL;
    }
    char *dup_str = (char*)malloc(strlen(str) + 1); // Allocate memory for the duplicate string
    if (dup_str == NULL) {
        printf("malloc failed\n");
        return NULL; // Return NULL to indicate failure
    }

    char *start = dup_str; // Save the start of the allocated memory
    while (*str) {
        *dup_str++ = *str++;
    }
    *dup_str = '\0'; // Null-terminate the new string

    return start; // Return the pointer to the start of the allocated memory
}

int main() {
    char *str = "Duplicate the string";
    char *dup_string = mystrdup(str);
    if (dup_string == NULL) {
        printf("Failed to duplicate string\n");
        return 1; // Return an error code
    }
    printf("Duplicate string: %s\n", dup_string);
    free(dup_string); // Free the allocated memory
    return 0;
}
