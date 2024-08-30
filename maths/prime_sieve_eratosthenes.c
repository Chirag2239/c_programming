/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void Seive_Eratosthenes(int num){
    int i = 0, p = 0, total_prime = 0;
    int *isPrime = malloc((num + 1) * sizeof(int));
    if(isPrime == NULL){
        return;
    }
    
    for(i = 2; i <= num; i++){
        isPrime[i] = 1;
    }
    
    isPrime[0] = isPrime[1] = 0;
    
    for(p = 2; p*p <= num; p++){
        if(isPrime[p]){
            for(i = p*p; i <= num; i += p){
                isPrime[i] = 0;
            }
        }
    }

    for (int p = 2; p <= num; p++) {
        if (isPrime[p]) {
            printf("%d ", p);
            total_prime++;
        }
    }
    
    printf("\ntotal_prime = %d\n", total_prime);
}

int main()
{
    printf("Reverse Number\n");
    Seive_Eratosthenes(23421);
    return 0;
}