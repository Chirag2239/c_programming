#include<stdio.h>

/* Intution: 
 * initialize large and secon large variable with -1.
 * Case 1: when the larger element is found, then existing larger becomes second largest.
 * Case 2: if the current number of array is same as second largest - ignore
 * Case 3: if the current numebr of array is lower than second largest:
 * **case 3.1: if this is the first second largest element: store it in second largest.
 * **case 3.2: if the current number is lower than second largest - ignore
 * **case 3.3: if there is new second largest element: store it in second largest.
*/
int second_largest(int arr[], int size){
    int largest = -1, sec_lrgst = -1;
    for(int i = 0; i < size; i++){
        //if this is the first number or the largest till now.
        if(arr[i] > largest){
            //the current largest becomes the second largest.
            sec_lrgst = largest;
            //new largest becomes the largest
            largest = arr[i];
        }

        //if the current element is not smaller than largest
        else if(arr[i] < largest){
            //There are two cases:
            //there is no new second largest till end-1, i.e. all the element except the last are same.
            //Else the end element is larger than the current second largest. 
            if((sec_lrgst == -1) || (sec_lrgst < arr[i])){
                sec_lrgst = arr[i];
            }
        }
    }
    return sec_lrgst;
}

int main(){
    //when all the elements are unique
    int arr[] = {3,23,24,6,5,3,57,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int res = second_largest(arr, size);
    printf("second largest element is : %d\n", res);

    //case when the second largest element is at the end
    int arr1[] = {3,6,8,1,6,6,7};
    size = sizeof(arr1)/sizeof(arr1[0]);
    res = second_largest(arr1, size);
    printf("second largest element is : %d\n", res);

    //case when the all the elements in the array are same except the last
    int arr2[] = {3,3,3,1};
    size = sizeof(arr2)/sizeof(arr2[0]);
    res = second_largest(arr2, size);
    printf("second largest element is : %d\n", res);
}