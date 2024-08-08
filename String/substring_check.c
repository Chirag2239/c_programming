#include <stdio.h>
#include <string.h>

int issubstring(char *str1, char *str2){
    int str1sz = strlen(str1);
    int str2sz = strlen(str2);
    if(str1sz < str2sz){
        return 0;
    }
    int i = 0, j = 0;
    for(i = 0; i <= str1sz - str2sz; i++){
        for(j = 0; j < str2sz; j++){
            if(str1[i+j] != str2[j]){
                break;
            }
        }
        if(j == str2sz){
            return 1;
        }
    }
    return 0;
}
int main(){
    char *str1 = "Good Morning";
    char *str2 = "Morning";
    int status = 0;
    status = issubstring(str1, str2);
    if(status){
        printf("str2 is a substring\n");
    }
    else{
        printf("str2 is not a substring\n");
    }
}