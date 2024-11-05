/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int two_sum(int *arr, int k, int size, int *result_arr){
    int i = 0, j = 0, sum;
    //int return_arr[2];
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            if(j != i){
                sum = arr[i] + arr[j];
                {
                    if(sum == k){
                        result_arr[0] = i;
                        result_arr[1] = j;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int main()
{
    printf("2Sum\n");
    int result_arr[2] = {0};
    int result = 0;
    int arr[] = {4,1,6,8,2,9,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    result = two_sum(arr, 15, size, result_arr);
    if(result){
        printf("two sum found at index %d and %d\n", result_arr[0], result_arr[1]);
    }
    else{
        printf("two sum not found\n");
    }
    return 0;
}
