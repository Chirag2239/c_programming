/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

char *toupper(char *str){
    char ch;
    int i = 0;
    while(str[i] != '\0'){
        ch = str[i];
        if((ch >= 'a') && (ch <= 'z')){
            str[i] = ch - 'a' + 'A';
        }
        i++;
    }
    return str;
}

char *tolower(char *str){
    char ch;
    int i = 0;
    while(str[i] != '\0'){
        ch = str[i];
        if((ch >= 'A') && (ch <= 'Z')){
            str[i] = ch - 'A' + 'a';
        }
        i++;
    }
    return str;
}

char *toggle(char *str){
    char ch;
    int i = 0;
    while(str[i] != '\0'){
        ch = str[i];
        if((ch >= 'A') && (ch <= 'Z')){
            str[i] = ch - 'A' + 'a';
        }
        else if((ch >= 'a') && (ch <= 'z')){
            str[i] = ch - 'a' + 'A';
        }
        i++;
    }
    return str;
}

int main()
{
    printf("String: toupper\n");
    char str[] = "Change the Lower case to Uppercase";
    char *str1 = toupper(str);
    printf("lower to upper case is : %s\n", str1);
    char str3[] = "ALWAYS CHECK THE string LETTER type";
    char *str4 = tolower(str3);
    printf("upper to lower case is : %s\n", str4);
    char str5[] = "ALWAYS check THE string LETTER type";
    str4 = toggle(str5);
    printf("toggled string is : %s\n", str4);
    return 0;
}
