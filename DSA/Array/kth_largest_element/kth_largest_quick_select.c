/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int partition(int *nums, int low, int high){
    int pivot = nums[low], temp = 0;
    int left = low + 1;
    int right = high;
    
    while(left <= right){
        if((nums[left] > pivot) && nums[right] < pivot){
            temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
        if(nums[left] <= pivot){
            left++;
        }
        if(nums[right] >= pivot){
            right--;
        } 
    }
    temp = nums[right];
    nums[right] = nums[low];
    nums[low] = temp;
    
    return right;
}

int findKthLargest(int* nums, int numsSize, int k) {
    int low = 0, high = numsSize - 1;
    int idx = 0, kth = 0;
    
    while(1){
        idx = partition(nums, low, high);
        if(idx == (numsSize - k)){
            kth = nums[idx];
            break;
        }
        if(idx < (numsSize - k)){
            low = idx + 1;
        }
        if(idx > (numsSize - k)){
            high = idx - 1;
        }
    }
    return kth;
}

int main()
{
    int arr[7] = {3,2,1,5,6,4};
    int result = 0;
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    result = findKthLargest(arr, arr_size, 2);
    printf("%d\n", result);
    return 0;
}