/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int majority_ele(int *arr, int size){
    int element = 0, count = 0;
    //Moore's voting algo
    for(int i = 0; i < size; i++){
        //if count = 0, then current element will be maximum and increment count.
        if(count == 0){
            element = arr[i];
            count++;
        }
        //if the current number is the element, increment count.
        else if(element == arr[i]){
            count++;
        }
        //if current number is not the element decrement count.
        else{
            count--;
        }
    }
    
    //count the occurance of element in an array.
    for(int i = 0; i < size; i++){
        if(element == arr[i]){
            count++;
        }
    }
    
    //check if the count is greater than the half of array size, then its majority.
    if(count > (size/2)){
        return element;
    }
    return 0;
}

int main()
{
    printf("Majority Element\n");
    int arr[] = {2,2,1,1,1,2,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    int maj = majority_ele(arr, size);
    printf("majority element = %d\n", maj);
    return 0;
}
