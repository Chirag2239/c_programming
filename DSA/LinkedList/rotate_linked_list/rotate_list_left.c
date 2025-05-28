/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node_t;

void CreateSortedList(node_t **head, int data){
    node_t *new_node = malloc(sizeof(node_t));
    node_t *curr = *head;
    new_node->data = data;
    if((curr == NULL) || (curr->data >= new_node->data)){
        new_node->next = curr;
        *head = new_node;
    }
    else{
        curr = *head;
        while((curr->next != NULL) && (curr->next->data <= new_node->data)){
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }
}

void rotateList(node_t **head, int rotation){
    int count = 1;
    if(*head == NULL || (*head)->next == NULL || rotation == 0){
        return;
    }
    node_t *curr = *head;
    while(curr->next != NULL){
        curr = curr->next;
        count++;
    }
    
    rotation = rotation % count;
    if(rotation == 0){
        return;
    }
    
    //make the list as circular linked list
    curr->next = *head;
    node_t *new_tail = *head;
    for(int i = 1; i < rotation; i++){
        new_tail = new_tail->next;
    }
    
    node_t *new_head = new_tail->next;
    new_tail->next = NULL;
    *head = new_head;
}

void printList(node_t *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    node_t *head = NULL;
    int rotation = 0;
    int list_arr[] = {3,1,7,8,9,-2,-3,0,5,4,2,6};
    int size = sizeof(list_arr)/sizeof(list_arr[0]);
    for(int i = 0; i < size; i++){
        CreateSortedList(&head, list_arr[i]);
    }
    printf("Sorted List:\n");
    printList(head);
    printf("\nrotate list left by :");
    scanf("%d", &rotation);
    rotateList(&head, rotation);
    printList(head);   
    return 0;
}