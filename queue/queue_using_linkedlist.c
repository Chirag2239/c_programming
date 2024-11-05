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

typedef struct Queue{
    struct node *front;
    struct node *rear;
}queue;

queue* createQueue(){
    queue *qu = malloc(sizeof(queue));
    qu->front = NULL;
    qu->rear = NULL;
    return qu;
}

struct node *createNode(unsigned int data){
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void enqueue(queue *qu, unsigned int data){
    struct node *new_node = createNode(data);
    if(qu->rear == NULL){
        qu->rear = new_node;
        qu->front = new_node;
        return;
    }
    qu->rear->next = new_node;
    qu->rear = new_node;
}

int dequeue(queue *qu){
    if((qu->rear == NULL) && (qu->front == NULL)){
        return -1;
    }
    else{
        struct node *temp = qu->front;
        qu->front = temp->next;
        free(temp);
    }
}

int myQueueRear(queue *qu){
    if((qu->rear == NULL) && (qu->front == NULL)){
        return -1;
    }
    else{
        return qu->rear->data;
    }
}

int myQueueFront(queue *qu){
    if((qu->rear == NULL) && (qu->front == NULL)){
        return -1;
    }
    else{
        return qu->front->data;
    }
}

int main()
{
    queue *qu = createQueue();
    enqueue(qu, 4);
    enqueue(qu, 2);
    enqueue(qu, 6);
    enqueue(qu, 9);
    //printStack(&st1);
    printf("Top is %d\n",myQueueRear(qu));
    printf("Front is %d\n",myQueueFront(qu));
    dequeue(qu);
    printf("Top is %d\n",myQueueRear(qu));
    printf("Front is %d\n",myQueueFront(qu));
    enqueue(qu, 1);
    dequeue(qu);
    printf("Top is %d\n",myQueueRear(qu));
    printf("Front is %d\n",myQueueFront(qu));
    return 0;
}