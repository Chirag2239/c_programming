/******************************************************************************

*******************************************************************************/
#include <stdio.h>
void toUpper(char *str1){
    while(*str1){
        if((*str1 >= 'a') && (*str1 <= 'z')){
            *str1 = *str1-'a'+'A';
        }
        str1++;
    }
}

int main()
{
    printf("strcmp\n");
    char str1[] = "convert lower to upper case";
    toUpper(str1);
    printf("toUpper output: %s\n", str1);
    return 0;
}