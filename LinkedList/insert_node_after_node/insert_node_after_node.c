#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    unsigned int data;
    struct node *next;
}node;

void insert_after_node(node **head_ref, int data, int target){
    node *new_node = (node*)malloc(sizeof(node));
    node *target_node = *head_ref;
    while(target_node->data != target)
    {
        target_node = target_node->next;
    }
    new_node->data = data;
    new_node->next = target_node->next;
    target_node->next = new_node;
}

void insert_at_beg(node **head_ref, int data){
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print_list(node *head){
    int count = 0;
    while(head != NULL){
        printf("node %d data is %d\n", count++, head->data);
        head = head->next;
    }
}

int main(){
    node *head = NULL;
    insert_at_beg(&head, 10);
    insert_at_beg(&head, 24);
    insert_at_beg(&head, 15);
    insert_at_beg(&head, 9);
    insert_at_beg(&head, 41);
    insert_after_node(&head, 17, 15);
    print_list(head);
    return 0;
}