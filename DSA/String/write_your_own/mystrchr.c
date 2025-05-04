/******************************************************************************
Returns the pointer to the first occurance of the character passed as arg.
*******************************************************************************/
#include <stdio.h>
char* mystrchr(char *str1, char ch){
    while(*str1){
        if(*str1 == ch){
            return str1;
        }
        str1++;
    }
}

int main()
{
    printf("strcmp\n");
    char str1[] = "CONVERT LOWER TO UPPER CASE";
    char *str2 = mystrchr(str1, 'P');
    printf("String after first occurance of char 'P': %s\n", str2);
    return 0;
}