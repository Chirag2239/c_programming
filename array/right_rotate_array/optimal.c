/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void reverse(int arr[], int left, int right){
    int temp = 0;
    while(left < right){
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

void rotate_right(int arr[], int size, int r_shift){
    reverse(arr, size - r_shift, size - 1);
    reverse(arr, 0, size - r_shift - 1);
    reverse(arr, 0, size - 1);
}

int main()
{
    int arr[7] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("size = %d\n", size);
    int r_shift = 3;
    rotate_right(arr, size,r_shift);
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}