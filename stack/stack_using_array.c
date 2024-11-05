#include <stdio.h>

#define MAX_CAPACITY 6
int curr_size = 0;
int top = -1;

void push(int *arr, int data){
    if(curr_size == MAX_CAPACITY){
        printf("stack is full\n");
        return;
    }
    top++;
    arr[top] = data;
    curr_size++;
}

int pop(int *arr, int *data)
{
    if(top == -1){
        printf("stack is empty\n");
        return -1;
    }
    *data = arr[top];
    top--;
    curr_size--;
    return data;
}

int st_top(int *arr){
    if(top == -1){
        printf("stack is empty\n");
        return -1;
    }
    return arr[top];
}

int main(){
    int i, element = 0, top_el = 0;
    int stack[MAX_CAPACITY];
    element = 4;
    push(stack, element);
    element = 8;
    push(stack, element);
    element = 21;
    push(stack, element);
    element = 19;
    push(stack, element);
    element = 1;
    push(stack, element);
    element = 14;
    push(stack, element);
    for(i = 0; i < MAX_CAPACITY; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
    top_el = st_top(stack);
    printf("%d\n", top_el);
    pop(stack, &element);
    top_el = st_top(stack);
    printf("%d\n", top_el);
    element = 2;
    push(stack, element);
    pop(stack, &element);
    top_el = st_top(stack);
    printf("%d\n", top_el);
    element = 4;
    push(stack, element);
    for(i = 0; i < MAX_CAPACITY; i++){
        printf("%d ", stack[i]);
    }
}