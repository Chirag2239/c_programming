/******************************************************************************

*******************************************************************************/
#include <stdio.h>

void mystrcat(char *str1, const char *str2){
    int i = 0, j = 0;
    while(*str1!='\0'){
        str1++;
    }

    while(*str2 != '\0'){
        *str1++ = *str2++;
    }
    *str1 = '\0';
}

int main()
{
    printf("strcat\n");
    char str1[50] = "Measure the length ";
    char str2[] = "of string";
    mystrcat(str1, str2);
    printf("strcat output: %s\n", str1);
    return 0;
}