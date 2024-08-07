/******************************************************************************

*******************************************************************************/
#include <stdio.h>
int mystrcmp(char *str1, const char *str2){
    int ret = -1;
    while((*str1 != NULL) && (*str2 != NULL)){
        if(*str1 < *str2){
            return -1;
        }
        else if(*str1 > *str2){
            return 1;
        }
        else{
            ret = 0;
        }
        str1++;
        str2++;
    }
    return ret;
}

int main()
{
    printf("strcmp\n");
    char *str1 = "copy one string With another string";
    char *str2 = "copy one string With another string";
    int res = mystrcmp(str1, str2);
    printf("strcmp output: %d\n", res);
    return 0;
}