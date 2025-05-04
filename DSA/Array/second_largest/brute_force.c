#include<stdio.h>

int largestNum(int arr[], int size){
    int i = 0;
    int largest = 0;
    for(i = 0; i < size; i++){
        if(arr[i] > arr[largest]){
            largest = i;
        }
    }
    return largest;
}

int second_largest(int arr[], int size){
    int largest = largestNum(arr, size);
    printf("arr largest is %d\n", largest);
    int i = 0;
    int sec_largest = -1;
    int sec_lrg_idx = 0;
    for(i = 0; i < size; i++){
        if(arr[i] != arr[largest]){
            if(arr[i] > sec_largest && (arr[i] < arr[largest])){
                sec_largest = arr[i];
                sec_lrg_idx = i;
            }
        }
    }
    return sec_largest;
}

int main(){
    int arr[] = {3,23,24,6,5,3,57,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int res = second_largest(arr, size);
    printf("second largest element is : %d\n", res);
}