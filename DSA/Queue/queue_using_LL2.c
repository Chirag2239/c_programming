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
}node_t;

typedef struct Queue{
    struct Node *front; //pointer to the node at front.
    struct Node *back;  //pointer to the node at back.
}queue_t;

void initQueue(queue_t **queue){
    *queue = malloc(sizeof(queue_t));
    (*queue)->front = NULL;
    (*queue)->back = NULL;
}

node_t* createNode(unsigned int data){
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push(queue_t **q_node, unsigned int data){
    node_t *new_node = createNode(data);
    queue_t *current = *q_node;
    if(current->back == NULL){
        current->front = new_node; //front points to new_node
        current->back = new_node;  //back points to new_node
        printf("first element %d entered to queue\n", current->back->data);
        return;
    }
    current->back->next = new_node; //existing node's next points to new_node
    current->back = new_node;   //back pointer is updated to new_node
    printf("element %d entered to queue\n", current->back->data);
}

int pop(queue_t **q_node){
    queue_t *current = *q_node;
    int data = current->front->data;
    if((current->front == NULL)){
        printf("Pop failed as queue is empty\n");
        return -1;
    }
    if(current->front == current->back){
        current->front = current->back = NULL;
        printf("Pop is completed for only one node %d\n", data);
        return data;
    }
    node_t *temp = current->front;
    current->front = temp->next;
    free(temp);
    printf("Pop is completed for data %d\n", data);
    return data;
}

int Peek(queue_t **q_node){
    queue_t *current = *q_node;
    if(current->front == NULL){
        printf("queue is empty\n");
        return -1;
    }
    printf("peek element is %d\n", (*q_node)->front->data);
    return (*q_node)->front->data;
}

int main()
{
    queue_t *queue = NULL;
    int pop_data = 0;
    initQueue(&queue);
    push(&queue, 8);
    pop_data = pop(&queue);
    Peek(&queue);
    push(&queue, 5);
    push(&queue, 1);
    push(&queue, 18);
    push(&queue, 12);
    pop_data = pop(&queue);
    pop_data = pop(&queue);
    Peek(&queue);
    push(&queue, 11);
    return 0;
}