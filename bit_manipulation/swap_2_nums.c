#include <stdio.h>
void SwapUsingXOR(int *num1, int *num2){
    *num1 = *num1 ^ *num2;
    *num2 = *num1 ^ *num2;
    *num1 = *num1 ^ *num2;
}

int main()
{
    int num1, num2;
    printf("enter num 1:");
    scanf("%d", &num1);
    printf("enter num 2:");
    scanf("%d", &num2);
    SwapUsingXOR(&num1, &num2);
    printf("after swap = num1 = %d and num2 = %d\n", num1, num2);
}