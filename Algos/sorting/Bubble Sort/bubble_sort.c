// Online C compiler to run C program online
#include <stdio.h>
#include <time.h>
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    printf("Bubbel Sort\n");
    int i, j;
    int arr[] = {39,1,5,7,2,8,4,6,9,25,21,18,16,11,10,13,17,20,19,24,22,27,26,29,30,14,23,38,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    clock_t start, end;
    double total_time;
    start = clock();
    for(i=0; i<n; i++){
        for(j = 0; j < n-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
    end = clock();
    total_time = ((double)(end - start))/*/CLOCKS_PER_SEC*/;
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\ntime taken in sorting = %f second\n", total_time);
    return 0;
}