/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
   return(*(int *)a - *(int *)b); 
}

int removeDuplicate(int arr[], int size){
    int i = 0;
    int new_index = 0;
    
    qsort(arr, size, sizeof(int), compare);
    
    while(i < size){
        if((i==0) || (arr[i] != arr[i - 1])){
            arr[new_index++] = arr[i];
        }
        i++;
    }
    return new_index;
}

int main()
{
    printf("Remove Duplicate\n");
    int arr[] = {2,3,6,1,6,2,8,9,0,7,11,54,0,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int result = removeDuplicate(arr, size);
    for(int i = 0; i < result; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}