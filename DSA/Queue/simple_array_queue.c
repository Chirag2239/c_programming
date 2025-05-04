#include <stdio.h>

#define MAX_CAPACITY 6
int curr_size = 0;
int start = -1, end = -1;

void push(int *arr, int data){
    //To overwrite the queue, following code should be commented.
    if(curr_size == MAX_CAPACITY){
        return;
    }
    //Check if the queue is empty
    if((start == -1) && (end == -1)){
        start++;
        end++;
    }
    else{
        end = (end + 1) % MAX_CAPACITY;
    }
    //data pushed at the back of the queue
    arr[end] = data;
    curr_size++;
}

int pop(int *arr)
{
    //check if the queue is empty
    if(curr_size == 0){
        return -1;
    }
    int data = arr[start];
    //if the popped element is the last element, queue is empty, so point pointers to -1.
    if(start == end){
        start = end = -1;
    }
    else{
        // the data pops out from front, so increment start.
        start = (start + 1) % MAX_CAPACITY;
    }
    //as the elements are popped, curr_size of queue should be reduced.
    curr_size--;
    return data;
}

int top(int *arr){
    //if the queue is empty, return 0.
    if(curr_size == 0){
        return 0;
    }
    //the top element is the front element as the data pops out from fornt.
    return arr[start];
}

int main(){
    int i, top_el = 0;
    int queue[MAX_CAPACITY];
    push(queue, 4);
    push(queue, 8);
    push(queue, 2);
    push(queue, 9);
    push(queue, 18);
    push(queue, 12);
    for(i = 0; i < MAX_CAPACITY; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
    top_el = top(queue);
    printf("%d\n", top_el);
    pop(queue);
    top_el = top(queue);
    printf("%d\n", top_el);
    push(queue, 2);
    pop(queue);
    top_el = top(queue);
    printf("%d\n", top_el);
    push(queue, 4);
    for(i = 0; i < MAX_CAPACITY; i++){
        printf("%d ", queue[i]);
    }
}