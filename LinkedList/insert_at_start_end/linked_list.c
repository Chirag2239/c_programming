#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    unsigned int data;
    struct node * next;
}node;

void insert_at_beg(node **head_ref, unsigned int data){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void print_list(node *head){
    int count = 0;
    while(head != NULL){
        printf("Element at node %d is %d\n", count, head->data);
        head = head->next;
    }
}

void insert_at_end(node **head_ref, unsigned int data){
    node *end_node = (node *)malloc(sizeof(node));
    node *last_node = *head_ref;
    end_node->next = NULL;
    end_node->data = data;
    if((*head_ref) == NULL){
        *head_ref = end_node;
        return;
    }
    while(last_node->next != NULL){
        last_node = last_node->next;
    }
    last_node->next = end_node;
}
int main()
{
    node *head = NULL;
    insert_at_beg(&head, 15);
    insert_at_beg(&head, 20);
    insert_at_beg(&head, 13);
    insert_at_end(&head, 8);
    insert_at_end(&head, 34);
    insert_at_end(&head, 39);
    print_list(head);
}