/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void reverseStr(char *str, int start, int end){
    char temp;
    while(start < end){
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void leftRotate(char *str, int d, int len){
    d = d%len;
    printf("d = %d\n", d);
    reverseStr(str, 0, d-1);
    printf("rotated string by d-1= %s\n", str);
    reverseStr(str, d, len-1);
    printf("rotated string by d to len-1= %s\n", str);
    reverseStr(str, 0, len-1);
    printf("rotated string = %s\n", str);
}

int main()
{
    printf("String Functions\n");
    char str[] = "WaterCooler";
    int strsize = strlen(str);
    printf("string size = %d\n", strsize);
    int rotationby = 3;
    leftRotate(str, rotationby, strsize);
    return 0;
}
