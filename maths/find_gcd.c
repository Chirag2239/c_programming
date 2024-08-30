#include <stdio.h>

int gcd(int a, int b){
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }
    if(a == b){
        return a;
    }
    int result = (a > b) ? a : b;
    while(result > 0){
        if((a % result == 0) && (b % result == 0)){
            break;
        }
    }
    return result;
}

int gcd_euclidian(int a, int b){
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }
    if(a == b){
        return a;
    }
    if(a > b){
        return gcd_euclidian(a - b, b);
    }
    else{
        return gcd_euclidian(a, b - a);
    }
}

int main()
{
    printf("GCD\n");
    int result = gcd(98, 56);
    printf("GCD of 98 and 56 = %d \n", result);
    result = gcd_euclidian(64, 48);
    printf("GCD of 64 and 48 = %d \n", result);
    return 0;
}