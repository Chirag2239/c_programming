/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int comp(void *a, void *b)
{
    return(*(int *)a - *(int *)b);
}

int two_sum(int *arr, int k, int size, int *result_arr){
    int left = 0, right = size - 1, sum = 0;
    while(left <= right){
        sum = arr[left] + arr[right];
        if(sum == k){
            result_arr[0] = left;
            result_arr[1] = right;
            return 1;
        }
        else if(sum < k){
            left++;
        }
        else{
            right--;
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
    qsort(arr, size, sizeof(int), comp);
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    result = two_sum(arr, 45, size, result_arr);
    if(result){
        printf("two sum found at index %d and %d\n", result_arr[0], result_arr[1]);
    }
    else{
        printf("two sum not found\n");
    }
    return 0;
}
