#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the doubly linked list
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a new node between nodes C and D
void insertNode(struct Node* C, struct Node* D, int value) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    // Update pointers to insert the new node between C and D
    newNode->next = D;
    newNode->prev = C;

    if (C != NULL)
        C->next = newNode;
    if (D != NULL)
        D->prev = newNode;
}

// Helper function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to demonstrate node insertion
int main() {
    // Create nodes
    struct Node* A = (struct Node*)malloc(sizeof(struct Node));
    struct Node* B = (struct Node*)malloc(sizeof(struct Node));
    struct Node* C = (struct Node*)malloc(sizeof(struct Node));
    struct Node* D = (struct Node*)malloc(sizeof(struct Node));
    struct Node* E = (struct Node*)malloc(sizeof(struct Node));

    // Assign values and connect nodes as per the example
    A->data = 50; A->next = B; A->prev = NULL;
    B->data = 60; B->next = C; B->prev = A;
    C->data = 70; C->next = D; C->prev = B;
    D->data = 80; D->next = E; D->prev = C;
    E->data = 90; E->next = NULL; E->prev = D;

    // Insert a new node between C and D with value 75
    insertNode(C, D, 75);

    // Print the list after insertion
    printList(A);

    return 0;
}
