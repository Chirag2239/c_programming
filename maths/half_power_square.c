/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
int power(int base, int expo){
    if(expo == 0){
        return 1;
    }
    if(expo == 1){
        return base;
    }
    if(expo % 2 == 0){
        int ex = expo/2;
        int halfpower = power(base, (expo/2));
        printf("Halfpower = %d and halfpower square = %d, ex = %d\n", halfpower, halfpower * halfpower, ex);
        return halfpower * halfpower;
    }
    else{
        int ex = expo;
        printf("ex = %d\n",ex);
        return (base * power(base, (expo - 1)));
    }
}

int main()
{
    printf("Calculate Power\n");
    int number, exponent = 0;
    printf("Enter the base: ");
    scanf("%d", &number);
    printf("Enter the exponent: ");
    scanf("%d",&exponent);
    int result = power(number, exponent);
    printf("%d", result);
    return 0;
}