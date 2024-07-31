#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int binary_search(int *nums, int numssize, int val){
    int left = 0, right = numssize - 1, mid = 0;
    while(left <= right){
        mid = (right + left)/2;
        if(val == nums[mid]){
            return mid;
        }
        else if(val < nums[mid]){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {10,34,36,21,93,30,54,15,2,9,72};
    int data=0, size=0, result = 0;
    size = sizeof(arr)/sizeof(arr[0]);
    qsort(arr, size, sizeof(int), cmpfunc);
    printf("enter num from 10,34,36,21,93,30,54,15,2,9,72 - \n");
    scanf("%d", &data);
    result = binary_search(arr, size, data);
    if(result != -1){
        printf("data is found at the index = %d\n", result);
    }
    else{
        printf("data is not found\n");
    }
}