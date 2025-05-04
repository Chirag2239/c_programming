/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

char *LargestWord(char *str, char *longest_str){
    char curr_str[100];
    int curr_len = 0, longest_len = 0, i = 0, j = 0;
    while(str[i] != '\0'){
        if((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')){
            curr_str[j] = '\0'; 
            if(curr_len > longest_len){
                longest_len = curr_len;
                strcpy(longest_str, curr_str);
            }
            j=0;
            curr_len = 0;
        }
        else{
            curr_str[j++] = str[i];
            curr_len++;
        }
        i++;
    }
    curr_str[j] = '\0';
    if(curr_len > longest_len){
        longest_len = curr_len;
        strcpy(longest_str, curr_str);
    }
    return longest_str;
}

int main()
{
    printf("Largest Word in string\n");
    char *str1 = "Population blast is not good for development";
    char longest_str[100] = {0};
    char *largestring = LargestWord(str1, longest_str);
    printf("Longest word : %s\n", largestring);
    return 0;
}
