/******************************************************************************

*******************************************************************************/
#include <stdio.h>
#include <string.h>
void toUpper(char *str1){
    while(*str1){
        *str1 = toupper(*str1);
        str1++;
    }
}

int main()
{
    printf("strcmp\n");
    char str1[] = "Convert lower to upper case";
    toUpper(str1);
    printf("toUpper output: %s\n", str1);
    return 0;
}