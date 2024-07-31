/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void countVowelConsonant(char *str1){
    int vowels = 0, consonant = 0;
    int size = strlen(str1);
    int i;
    for(i=0; i<size; i++){
        char ch = tolower(str1[i]);
        if((ch >= 'a') && (ch <= 'z')){
            if((ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u')){
                vowels++;
            }
            else{
                consonant++;
            }
        }
    }
    printf("vowels = %d and consonant = %d\n", vowels,consonant);
}

void concateString(char *str1, char *str2){
    int i = 0, j = 0;
    while(str1[i] != '\0'){
        i++;
    }
    while(str2[j] != '\0'){
        str1[i++] = str2[j++];
    }
    str1[i] = '\0';
}

int findSubstring(char *mainstr, char *substr){
    int mainlen = strlen(mainstr);
    int sublen = strlen(substr);
    int i, j;
    for(i = 0; i < mainlen; i++){
        for(j=0; j<sublen; j++){
            if(mainstr[i+j] != substr[j]){
                break;
            }
        }
        if(j == sublen){
            return 1;
        }
    }
    return 0;
}
int main()
{
    int issubstr = 0;
    printf("count num of vowels and consonant\n");
    char *str = "Hello World What are you doing?";
    countVowelConsonant(str);
    char str2[20] = "Ping Pong";
    char str3[20] = "Pong Ping";
    concateString(str2, str3);
    printf("concatanated string = %s\n", str2);
    char *str4 = "Man goes to Toilet";
    char *str5 = "";
    issubstr = findSubstring(str4, str5);
    if(issubstr){
        printf("string is substring\n");
    }
    else{
        printf("string is not substring\n");
    }
    return 0;
}
