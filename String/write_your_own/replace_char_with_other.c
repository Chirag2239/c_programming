/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void replace_char(char *str, char tobe_rep_char, char rep_char) {
    // Check for NULL or empty string
    if (str == NULL || *str == '\0') {
        return;
    }
    while(*str){
        if(*str == tobe_rep_char){
            *str = rep_char;
        }
        str++;
    }
}

int main() {
    char str[] = "Hello, World!";
    char rep_char = 's';
    char all_char = 'l';
    printf("Original: '%s'\n", str);
    replace_char(str, all_char, rep_char);
    printf("\n");
    printf("Updated: '%s'\n", str);
    return 0;
}

