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

void delete_at_end(node **head_ref){
    node *temp = (*head_ref);
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = temp->next->next;
    free(temp);
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
    print_list(head);
    printf("\n");
    delete_at_end(&head);
    print_list(head);
    printf("\n");
    insert_at_end(&head, 39);
    print_list(head);
}