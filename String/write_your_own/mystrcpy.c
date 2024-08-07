/******************************************************************************

*******************************************************************************/
#include <stdio.h>

char* mystrcpy(char *destination, const char *source){
    while(*source!='\0'){
        *destination++ = *source++;
    }
    *destination = '\0';
    return destination;
}

int main()
{
    printf("strcpy\n");
    char str1[50] = "Copy one string to another string";
    char str2[] = {'\0'};
    mystrcpy(str2, str1);
    printf("strcpy output: %s\n", str2);
    return 0;
}