// Online C compiler to run C program online
#include <stdio.h>
void swap(int *a, int *b){
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int arr[8] = {3,2,4,6,1,7,9,5};
    int i = 0, j = 0;
    int temp;
    for(i = 1; i < 8; i++){
        j = i;
        while((j > 0) && (arr[j] < arr[j - 1])){
            swap(&arr[j], &arr[j-1]);
            j--;
        }
    }
    for(i = 0; i < 8; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}