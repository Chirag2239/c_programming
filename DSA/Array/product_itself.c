#include <stdio.h>
#include <stdlib.h>
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *arr = malloc(numsSize*sizeof(int));
    *returnSize = numsSize;
    int result = 1, start = 0;
    while(start < numsSize){
        int i = 0;
        result = 1;
        while(i < numsSize){
            if(i != start){
                printf("start = %d, i = %d\n", start, i);
                result = result * nums[i];
            }
            i++;
        }
        arr[start++] = result;
    }
    return arr;
}
int main(){
    int size = 4;
    int retSize;
    int *result = malloc(size*sizeof(int));
    int nums[] = {1,2,3,4};
    result = productExceptSelf(nums, 4, &retSize);
    for(int i=0; i < size; i++){
        printf("%d\n", result[i]);
    }
}