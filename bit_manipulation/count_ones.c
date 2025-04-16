#include <stdio.h>

/* 
 * Iterations	    - 𝑂(𝑘), where 𝑘 is the number of 1s
 * Performance      - Faster for sparse binary numbers
 * Real-World Usage - More efficient for large numbers with few 1s
*/
int Count1s(int num){
    int count = 0;
    while(num){
        num = num & (num - 1);
        count++;
    }
    return count;
}

int main()
{
    int num = 24;
    int result = Count1s(num);
    printf("%d", result);
}