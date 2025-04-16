#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node_t;

void insert(node_t **head, int data){
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
        return;
    }
    node_t *temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
}

void printList(node_t *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int intersection(node_t *head1, node_t *head3){
    node_t *d1 = head1;
    node_t *d2 = head3;

    while(d1 != d2){
        d1 = (d1 == NULL)?head3:d1->next;
        d2 = (d2 == NULL)?head1:d2->next;
    }
    return (d1->data);
}

int main(){
    node_t *head1 = NULL;
    node_t *head2 = NULL;
    node_t *head_h2 = NULL;
    node_t *head_h1 = NULL;
    insert(&head1, 9);
    insert(&head1, 7);
    insert(&head1, 3);
    insert(&head1, 6);
    insert(&head1, 8);
    insert(&head1, 4);
    head_h1 = head1;
    head1 = head1->next->next->next;
    insert(&head2, 2);
    insert(&head2, 1);
    insert(&head2, 6);
    insert(&head2, 0);
    head_h2 = head2;
    head2->next->next->next->next = head1;
    printList(head_h1);
    printf("\n");
    printList(head_h2);
    printf("\n");
    printList(head1);
    printf("\n");
    printList(head2);
    int intpoint = intersection(head_h1, head2);
    printf("\n%d\n", intpoint);
}