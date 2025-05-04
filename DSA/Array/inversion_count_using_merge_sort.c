/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int merge(int arr[], int left, int mid, int right){
    int lsz = mid - left + 1;
    int rsz = right - mid;
    int i = 0, j = 0, k = left;
    int inver_cnt = 0;
    
    int *LP = malloc (sizeof(int) * lsz);
    int *RP = malloc (sizeof(int) * rsz);
    
    for(i = 0; i < lsz; i++){
        LP[i] = arr[left+i];
    }
    for(j = 0; j < rsz; j++){
        RP[j] = arr[mid + 1 + j];
    }
    i = 0, j = 0;
    while((i < lsz) && (j < rsz)){
        if(LP[i] <= RP[j]){
            arr[k++] = LP[i++];
        }
        else{
            arr[k++] = RP[j++];
            inver_cnt += lsz - i;
        }
    }
    while(i < lsz){
        arr[k++] = LP[i++];
    }
    while(j < rsz){
        arr[k++] = RP[j++];
    }
    return inver_cnt;
}

int mergesort(int arr[], int left, int right){
    int count = 0;
    if(left < right){
        int mid = left + (right-left)/2;
        count += mergesort(arr, left, mid);
        count += mergesort(arr, mid + 1, right);
        count += merge(arr, left, mid, right);
    }
    return count;
}

int main()
{
    printf("Merge Sort\n");
    int arr[] = {5,2,7,8,9,2,6,1,3,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int low = 0, high = size-1;
    int in_cnt = mergesort(arr, low, high);
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\nInversion Count = %d\n",in_cnt);
    return 0;
}