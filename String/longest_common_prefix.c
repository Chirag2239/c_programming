#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *largestCommonPrefix(char **str, int size){
    if(size == 0){
        return "";
    }
    char *prefix = malloc(30*sizeof(char));
    strcpy(prefix, str[0]);
    for(int i = 1; i<size; i++){
        int j = 0;
        while((prefix[j]!='\0') && (str[i][j]!='\0') && (prefix[j]==str[i][j])){
            j++;
        }
        prefix[j]='\0';
    }
    return prefix;
}
int main(){
    char *strs[] = {"flower", "flow", "flight"};
    int strssize = sizeof(strs)/sizeof(strs[0]);
    printf("%d\n", strssize);
    char *prefix = largestCommonPrefix(strs, strssize);
    printf("Largest common Prefix is: %s\n", prefix);
}