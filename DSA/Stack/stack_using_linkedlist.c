/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node {
    unsigned int data;
    struct node * next;
};

/* 
 * encapsulate the node with struct stack.
 * or imagine the required pointers to maintain stack is only one, which is head.
 * This can be used for traversal, push, pop, top and destroy functions.
 * So it provides ease of management in stack.
*/
typedef struct stack{
    struct node *head;
}stack;

void initStack(stack *st1){
    st1->head = NULL;
}

void push(stack *st1, unsigned int data){
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = st1->head;
    st1->head = new_node;
}

int pop(stack *st1){
    if(st1->head == NULL){
        return -1;
    }
    else{
        struct node *temp = st1->head;
        st1->head = temp->next;
        free(temp);
    }
}

int myStackTop(stack *st1){
    if(st1->head == NULL){
        return -1;
    }
    else{
        return st1->head->data;
    }
}

void printStack(stack *st1){
    while(st1->head != NULL){
        printf("%d ", st1->head->data);
        st1->head = st1->head->next;
    }
}

int main()
{
    stack st1;
    initStack(&st1);
    push(&st1, 4);
    push(&st1, 2);
    push(&st1, 6);
    push(&st1, 9);
    push(&st1, 1);
    //printStack(&st1);
    printf("Top is %d\n",myStackTop(&st1));
    pop(&st1);
    printf("Top is %d\n",myStackTop(&st1));
    return 0;
}