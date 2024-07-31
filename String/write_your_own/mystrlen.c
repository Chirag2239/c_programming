/******************************************************************************

*******************************************************************************/
#include <stdio.h>
#include <string.h>

unsigned int count = 0;

unsigned int mystrlen(char *str){
    int i = 0;
    while(str[i++]!='\0'){
        count++;
    }
    return count;
}

int main()
{
    printf("strlen\n");
    unsigned int strsize = 0;
    char str[] = "Measure the length of string";
    strsize = mystrlen(str);
    printf("size of string: %d\n", count);
    return 0;
}