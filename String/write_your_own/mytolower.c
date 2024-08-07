/******************************************************************************

*******************************************************************************/
#include <stdio.h>
void toUpper(char *str1){
    while(*str1){
        if((*str1 >= 'A') && (*str1 <= 'Z')){
            *str1 = *str1-'A'+'a';
        }
        str1++;
    }
}

int main()
{
    printf("strcmp\n");
    char str1[] = "CONVERT LOWER TO UPPER CASE";
    toUpper(str1);
    printf("toUpper output: %s\n", str1);
    return 0;
}