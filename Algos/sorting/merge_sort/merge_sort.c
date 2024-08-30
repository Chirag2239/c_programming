/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right){
    int left_len = mid - left + 1;
    int right_len = right - mid;
    int i = 0, j = 0;
    int *LP = malloc(left_len * sizeof(int));
    int *RP = malloc(right_len * sizeof(int));
    
    for(i=0; i < left_len; i++){
        LP[i] = arr[left+i];
    }
    for(j=0; j < right_len; j++){
        RP[j] = arr[mid + 1 + j];
    }
    
    i = 0; j = 0;
    int k = left;
    while((i < left_len) && (j < right_len)){
        if(LP[i] <= RP[j]){
            arr[k++] = LP[i++];
        }
        else{
            arr[k++] = RP[j++];
        }
    }
    while(i < left_len){
        arr[k++] = LP[i++];
    }
    while(j < right_len){
        arr[k++] = RP[j++];
    }
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left + (right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    printf("Merge Sort\n");
    int arr[] = {2,3,6,1,6,2,8,9,0,7,11,54,0,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int low = 0, high = size-1;
    mergeSort(arr, low, high);
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}