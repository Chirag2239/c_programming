/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <limits.h>

int reverse_num(int num){
    int temp = 0;
    int digit = 0;
    while(num > 0){
        digit = num % 10;
        temp = (temp*10) + digit;
        num = num / 10;
    }
    return temp;
}

int main()
{
    printf("Reverse Number\n");
    int result = reverse_num(23421);
    printf("reversed number is = %d \n", result);
    return 0;
}