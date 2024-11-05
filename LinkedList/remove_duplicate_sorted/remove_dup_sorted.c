#include <stdio.h>
#include <stdlib.h>

// Definition for a singly-linked list node
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to print the linked list (for testing purposes)
void printList(struct ListNode *head) {
    struct ListNode *current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

// Function to remove duplicates from a sorted linked list
void removeDuplicates(struct ListNode *head) {
    if((head == NULL) || (head->next == NULL)){
        return;
    }
    struct ListNode *curr = head;
    struct ListNode *temp = NULL;
    while(curr->next != NULL){
        if(curr->val == curr->next->val){
            temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }
        else{
            curr = curr->next;
        }
    }
}

// Function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (node == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to create a sorted linked list from an array
struct ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;

    struct ListNode *head = newNode(arr[0]);
    struct ListNode *current = head;

    for (int i = 1; i < n; ++i) {
        current->next = newNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Function to deallocate memory used by the linked list
void freeList(struct ListNode *head) {
    struct ListNode *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int arr[] = {1, 1, 2, 3, 3, 3, 4, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create a sorted linked list from array
    struct ListNode *head = createList(arr, n);

    printf("Original linked list: ");
    printList(head);

    // Remove duplicates
    removeDuplicates(head);

    printf("Linked list after removing duplicates: ");
    printList(head);

    // Free memory allocated for linked list
    freeList(head);

    return 0;
}
