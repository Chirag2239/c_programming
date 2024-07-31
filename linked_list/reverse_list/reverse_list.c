#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    unsigned int data;
    struct node *next;
}node;

void insert_at_beg(node **head_ref, unsigned int data){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = (*head_ref);
    *head_ref = new_node;
}

void insert_at_end(node **head_ref, unsigned int data){
    node *end_node = (node*)malloc(sizeof(node));
    node *last_node = (*head_ref);
    if((*head_ref) == NULL){
        *head_ref = end_node;
        return;
    }
    while(last_node->next != NULL){
        last_node = last_node->next;
    }
    end_node->data = data;
    end_node->next = NULL;
    last_node->next = end_node;
}

void reverse_list(node **head_ref){
    node *prev = NULL;
    node *next = NULL;
    node *curr = (*head_ref);
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    (*head_ref) = prev;
}

void reverse_between(node **head_ref, int right, int left){
    node *curr = *head_ref;
    node *next = NULL;
    node *prev = NULL;
    node *left_prev = NULL;
    node *left_node = NULL;
    // node *right_next = NULL;
    
    while(curr->data != left){
        prev = curr;
        curr = curr->next;
    }
    
    left_node = curr;
    left_prev = prev;
    // right_next = curr->next;
    
    while(curr->data != right){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    next = curr->next;
    curr->next = prev;
    left_prev->next = curr;
    left_node->next = next;
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
    insert_at_beg(&head, 45);
    insert_at_beg(&head, 24);
    insert_at_beg(&head, 74);
    insert_at_end(&head, 88);
    insert_at_end(&head, 34);
    insert_at_end(&head, 39);
    print_list(head);
    printf("\nreversed list\n");
    reverse_list(&head);
    print_list(head);
    printf("\nelement reversed list\n");
    reverse_between(&head,24,34);
    print_list(head);
}