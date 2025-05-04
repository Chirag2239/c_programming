#include <stdio.h>

int is_sorted(int *arr, int size){
    int i = 1;
    while(i < size){
        if(arr[i] < arr[i - 1]){
            return 0;
        }
        i++;
    }
    return 1;
}

int main(){
    int arr[] = {3,23,24,6,5,3,57,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int res = is_sorted(arr, size);
    if(res){
        printf("the array is sorted\n");
    }
    else{
        printf("the array is not sorted\n");
    }

    int arr2[] = {1,2,3,5,6,23,24,57};
    size = sizeof(arr2)/sizeof(arr2[0]);
    res = is_sorted(arr2, size);
    if(res){
        printf("the array is sorted\n");
    }
    else{
        printf("the array is not sorted\n");
    }
}