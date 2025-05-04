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
    struct node *next;
}node;

node *merge(node *front, node *back){
    node *tail = NULL;
    if(front == NULL){
        return back;
    }
    if(back == NULL){
        return front;
    }
    
    if(front->data <= back->data){
        tail = front;
        tail->next = merge(front->next, back);
    }
    else{
        tail = back;
        tail->next = merge(front, back->next);
    }
    return tail;
}

void split(node *source, node **front, node **back){
    node *slow = source;
    node *fast = source->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    
    *front = source;
    *back = slow->next;
    slow->next = NULL;
}

void mergesort(node **head_ref){
    node *head = *head_ref;
    node *a;
    node *b;
    
    if(head == NULL || head->next == NULL){
        return;
    }
    
    split(head, &a, &b);
    
    mergesort(&a);
    mergesort(&b);
    
    *head_ref = merge(a, b);
}

void push(node **head, unsigned int data){
    node *new = (node*)malloc(sizeof(node));
    new->data = data;
    new->next = *head;
    *head = new;
}

void printlist(node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
     node *head = NULL;
     push(&head, 13);
     push(&head, 12);
     push(&head, 5);
     push(&head, 2);
     push(&head, 10);
     push(&head, 18);
     
     printlist(head);
     
     mergesort(&head);
     printf("\nAfter sort\n");
     printlist(head);

    return 0;
}
