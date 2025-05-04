#include <stdio.h>
int FindNonRepeating(int *num_arr, int arr_size){
    int i = 0;
    int non_repeating_num = 0;
    for(int i = 0; i < arr_size; i++){
        non_repeating_num = non_repeating_num ^ num_arr[i];
    }
    return non_repeating_num;
}
int main()
{
    int arr[7] = {4,7,1,3,4,1,3};
    int result = 0;
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    result = FindNonRepeating(arr, arr_size);
    printf("%d\n", result);
    return 0;
}