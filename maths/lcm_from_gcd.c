/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <limits.h>

int gcd(int a, int b){
    while(b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b){
    if(a == 0 || b == 0){
        return 0;
    }
    return (a/gcd(a,b))*b;
}

int main()
{
    printf("LCM from GCD\n");
    int result = lcm(98, 56);
    printf("GCD of 98 and 56 = %d \n", result);
    return 0;
}