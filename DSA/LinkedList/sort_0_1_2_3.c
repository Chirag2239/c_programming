#include <stdio.h>
#include <stdlib.h>

// Define the structure of the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to sort the linked list of 0s, 1s, and 2s
struct Node* sortLinkedList(struct Node* head) {
    struct Node *zeroTail = NULL, *oneTail = NULL, *twoTail = NULL;
    struct Node *current = head;

    // Traverse and rearrange nodes directly into 0, 1, and 2 sections
    while (current != NULL) {
        struct Node* nextNode = current->next;  // Save the next node

        if (current->data == 0) {
            current->next = zeroTail;             // Add node at zeroTail
            zeroTail = current;                   // Update zeroTail
        } else if (current->data == 1) {
            current->next = oneTail;              // Add node at oneTail
            oneTail = current;                    // Update oneTail
        } else {
            current->next = twoTail;              // Add node at twoTail
            twoTail = current;                    // Update twoTail
        }

        current = nextNode;  // Move to the next node
    }

    // Connect 0s, 1s, and 2s together based on available segments
    head = zeroTail ? zeroTail : (oneTail ? oneTail : twoTail);

    if (zeroTail) {
        struct Node* lastZero = zeroTail;
        while (lastZero->next) lastZero = lastZero->next;
        lastZero->next = oneTail ? oneTail : twoTail;
    }
    
    if (oneTail) {
        struct Node* lastOne = oneTail;
        while (lastOne->next) lastOne = lastOne->next;
        lastOne->next = twoTail;
    }

    return head;
}

// Main function to test the sort function
int main() {
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(0);
    head->next->next->next = createNode(1);
    head->next->next->next->next = createNode(2);
    head->next->next->next->next->next = createNode(0);

    head = sortLinkedList(head);
