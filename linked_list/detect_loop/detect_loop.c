/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct node{
    unsigned int data;
    struct node *next;
};

int detectLoop(struct node **head_ref){
    struct node *slow = *head_ref;
    struct node *fast = *head_ref;
    
    while((slow != NULL) && (fast != NULL) && (fast->next != NULL)){
        slow = slow->next;
        fast = fast->next->next;
        
        if(fast == slow){
            return 1;
        }
    }
    return 0;
}

struct node *firstNode = NULL;

void push(struct node **head_loc, unsigned int data){
    struct node *new_node = malloc(sizeof(struct node));
    struct node *curr = NULL;
    new_node->data = data;
    
    if((*head_loc == NULL) || (new_node->data <= (*head_loc)->data)){
        new_node->next = *head_loc;
        *head_loc = new_node;
    }
    else{
        curr = *head_loc;
        while((curr->next != NULL) && (curr->next->data <= new_node->data)){
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next = new_node;
    }

}

void printList(struct node *head){
    while(head != NULL){
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main()
{
    struct node *head = NULL;
    int i = 0;
    printf("Sorting Linked List during creation\n");
    int data;
    for(i = 0; i < 6; i++){
        printf("Enter the data for node %d:", i);
        scanf("%d", &data);
        push(&head, data);
        printList(head);
    }
    
    head->next->next->next->next->next = head;
    
    if(detectLoop(&head)){
        printf("Loop detected\n");
    }
    else{
        printf("No Loop detected\n");
    }
    return 0;
}