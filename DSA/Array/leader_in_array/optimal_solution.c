#include <stdio.h>

void Arrleader(int *arr, int size){
    int i = 0;
    int curr_ldr = arr[size - 1];
    printf("%d ", curr_ldr);
    for(i = size - 2; i >= 0; i--){
        if(arr[i] > curr_ldr){
            curr_ldr = arr[i];
            printf("%d ", curr_ldr);
        }
    }
}

int main(){
    int arr[] = {3,23,24,6,5,3,57,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    Arrleader(arr, size);
}