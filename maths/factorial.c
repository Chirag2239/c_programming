/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <limits.h>

int factorial(int num){
    if(num >= INT_MAX){
        return 0;
    }
    if(num == 0 || num == 1){
        return 1;
    }
    return (num * factorial(num - 1));
}

int fac(int num){
    int i = 0, result = 1;
    if(num == 0 || num == 1){
        return 1;
    }
    for(i = num; i > 0; i--){
        result = i * result;
    }
}

int main()
{
    printf("Factorial\n");
    int result = factorial(5);
    printf("%d ", result);
    result = fac(5);
    printf("\n%d ", result);
    return 0;
}