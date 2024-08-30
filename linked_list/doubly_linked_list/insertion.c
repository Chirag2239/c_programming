/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    unsigned int data;
    struct node *prev;
    struct node *next;
}Node;

void push(Node **head, unsigned int data){
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = *head;
    if(*head != NULL){
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void printList(Node *head){
    Node *end = NULL;
    printf("\nForward traverse\n");
    while(head != NULL){
        end = head;
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\nBackward Traverse\n");
    while(end != NULL){
        printf("%d ", end->data);
        end = end->prev;
    }
}

void pushAtEnd(Node **head, unsigned int data){
    Node *new_node = malloc(sizeof(Node));
    Node *current = NULL;
    new_node->data = data;
    new_node->next = NULL;
    if(*head == NULL){
        new_node->next = NULL;
        *head = new_node;
        return;
    }
    current = *head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

void insertAfterNode(Node **head, unsigned int data, unsigned int node_data){
    Node *new_node = malloc(sizeof(Node));
    Node *current = *head;
    new_node->data = data;
    while(current->data != node_data){
        current = current->next;
    }
    new_node->next = current->next;
    current->next->prev = new_node;
    current->next = new_node;
    new_node->prev = current;
}

int main()
{
    Node *head = NULL;
    push(&head, 5);
    push(&head, 15);
    push(&head, 2);
    printList(head);
    pushAtEnd(&head, 13);
    printList(head);
    insertAfterNode(&head, 8, 15);
    printList(head);
    return 0;
}