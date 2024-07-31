#include <stdio.h>

int linear_search(int *nums, int numssize, int val){
    int i = 0;
    for(i = 0; i<numssize; i++){
        if(nums[i] == val){
            return i;
        }
    }
    return 0;
}
int main(){
    int arr[] = {10,34,36,21,93,30,54,15,2,9,72};
    int size = sizeof(arr)/sizeof(arr[0]);
    int data = 0;
    printf("enter the data from 10,34,36,21,93,30,54,15,2,9,72 - \n");
    scanf("%d", &data);
    int result = linear_search(arr, size, data);
    if(result != 0){
        printf("the data is found at index = %d\n", result);
    }
    else{
        printf("the data is not found\n");
    }
}