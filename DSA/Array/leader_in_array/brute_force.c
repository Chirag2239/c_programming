#include <stdio.h>

void Arrleader(int *arr, int size){
    int i = 0, j = 0;

    for(i = 0; i < size; i++){
        int curr_flag = 0;
        for(j = i + 1; j < size; j++){
            if(arr[i] <= arr[j]){
                curr_flag = 1;
                break;
            }
        }
        if(curr_flag == 0){
            printf("%d ", arr[i]);
        }
    }
}

int main(){
    int arr[] = {3,23,24,6,5,3,57,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    Arrleader(arr, size);
}