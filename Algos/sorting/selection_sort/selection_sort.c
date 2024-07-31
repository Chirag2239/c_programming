#include <stdio.h>

void swap(int *a, int *b){
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int arr[8] = {3,2,4,6,1,7,9,5};
    int i = 0, j = 0;
    for(i = 0; i < 7; i++){
        int curr_min = i;
        for(j = i+1; j < 8; j++){
            if(arr[j] < arr[curr_min]){
                curr_min = j;
            }
        }
        if(curr_min != i){
            swap(&arr[curr_min], &arr[i]);
        }
    }
    for(i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}