/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int num){
    int i = 0;
    int a = 0, b = 1, c = 0;
    if(num <= 1){
        return num;
    }
    for(i = 2; i <= num; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int rec_fibo(num){
    if(num <= 1){
        return num;
    }
    return rec_fibo(num - 1) + rec_fibo(num - 2);
}

int main()
{
    printf("Reverse Number\n");
    int result = fibonacci(10);
    printf("%d\n", result);
    result = rec_fibo(10);
    printf("%d\n", result);
    return 0;
}