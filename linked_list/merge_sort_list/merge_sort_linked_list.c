#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to merge two sorted linked lists
struct Node* merge(struct Node* left, struct Node* right) {
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    struct Node* result = NULL;

    if (left->data <= right->data) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// Function to split the linked list into two halves
void split(struct Node* source, struct Node** left, struct Node** right) {
    struct Node* slow = source;
    struct Node* fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *left = source;
    *right = slow->next;
    slow->next = NULL;
}

// Merge sort function for linked list
void mergeSort(struct Node** headRef) {
    struct Node* head = *headRef;
    struct Node* left;
    struct Node* right;

    if (head == NULL || head->next == NULL)
        return;

    split(head, &left, &right);

    mergeSort(&left);
    mergeSort(&right);

    *headRef = merge(left, right);
}

// Function to add a new node to the beginning of the linked list
void push(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Driver program to test above functions
int main() {
    struct Node* head = NULL;
    push(&head, 15);
    push(&head, 10);
    push(&head, 5);
    push(&head, 20);
    push(&head, 3);
    push(&head, 2);

    printf("Linked List before sorting \n");
    printList(head);

    mergeSort(&head);

    printf("\nLinked List after sorting \n");
    printList(head);

    return 0;
}
