/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

void rotate_right(int arr[], int size, int r_shift){
    int temp[r_shift];
    int i = 0;
    
    for(i = 0; i < r_shift; i++){
        temp[i] = arr[(size - r_shift) + i];
    }

    for(i = 0; i < r_shift + 1; i++){
        arr[size - i - 1] = arr[size - r_shift - i - 1]; 
    }
    
    for(i = 0; i < r_shift; i++){
        arr[i] = temp[i];
    }
    
    for(i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}
int main()
{
    int arr[7] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("size = %d\n", size);
    int r_shift = 3;
    rotate_right(arr, size,r_shift);

    return 0;
}