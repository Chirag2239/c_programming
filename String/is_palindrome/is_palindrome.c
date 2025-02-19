/******************************************************************************
 * input = long string with the whitespace.
 * This code will accept the long string including whitespace.
 * First it will remove the whitespace from the sting using strtok().
 * strtok() will create the new string.
 * Then code will check if the string is palindrome or not.
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_palindrome(char *str){
    if(str == NULL){
        return 0;
    }
    int size = strlen(str);
    char *str2 = malloc(sizeof(char) * size);
    char *temp = strtok(str, " ");
    while(temp != NULL){
        strcat(str2, temp);
        temp = strtok(NULL, " ");
    }
    printf("%s\n", str2);
    for(int i = 0; i < (size/2); i++){
        if(str2[i] != str[size - i - 1]){
            return 0;
        }
    }
    printf("str2 = %s\n", str2); 
    return 1;
}

int main()
{
    char str1[] = "Was it a car or a cat i saW";
    int status = 0;
    if(is_palindrome(str1)){
        printf("string is not palindrome\n");
    }
    else{
        printf("string is palindrome\n");
    }
    return 0;
}