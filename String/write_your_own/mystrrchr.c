/******************************************************************************
 * Syntax: char* strrchr( char* str, int chr );
 * Return: The function returns a pointer to the last location of ch 
 *         in the string if the str is found.
 *         If chr is not found, it returns a null pointer.
*******************************************************************************/
#include <stdio.h>

char* mystrchr(char *str1, char ch){
    int *last_idx=NULL;
    while(*str1){
        if(*str1 == ch){
            last_idx = str1;
        }
        str1++;
    }
    return last_idx;
}

int main()
{
    printf("strcmp\n");
    char str1[] = "CONVERT LOWER TO UPPER CASE";
    char *str2 = mystrchr(str1, 'P');
    printf("strchr output: %s\n", str2);
    str2 = mystrchr(str1, 'M');
    printf("strchr output: %s\n", str2);
    return 0;
}