/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
    printf("Reverse String\n");
    char str1[] = "Good Morning with string reversal";
    char temp;
    int i = 0;
    int ssize = strlen(str1);
    for(i=0; i<(ssize/2); i++){
        temp = str1[i];
        str1[i] = str1[ssize-i-1];
        str1[ssize-i-1] = temp;
    }
    printf("reversed string = %s\n", str1);
    return 0;
}
