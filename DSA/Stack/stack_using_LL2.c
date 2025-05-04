/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    unsigned int data;
    struct Node * next;
}node;

int stack_size = 0;

void push(node **head, unsigned int data){
    node *new = malloc(sizeof(node));
    new->data = data;
    new->next = *head;
    *head = new;
    stack_size++;
}

int pop(node **head){
    if(stack_size == 0){
        printf("stack is empty\n");
        return 0;
    }
    node *temp = *head;
    int data = temp->data;
    *head = temp->next;
    free(temp);
    stack_size--;
}

int myStackTop(node *head){
    return head->data;
}

void printStack(node *head){
    node *current = head;
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}

int main()
{
    node *st1 = NULL;
    pop(&st1);
    push(&st1, 4);
    push(&st1, 2);
    push(&st1, 6);
    push(&st1, 9);
    push(&st1, 1);
    printStack(st1);
    printf("\n");
    printf("Top is %d\n",myStackTop(st1));
    pop(&st1);
    printf("Top is %d\n",myStackTop(st1));
    return 0;
}