#include <stdio.h>
#include <stdlib.h>

// Define the structure for a single linked list node
typedef struct node {
    int data;                // Data part of the node
    struct node* next;       // Pointer to the next node
} node;

// Function to create a new node
node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the list
void appendNode(node** head, int data) {
    node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node with data %d appended.\n", data);
}

// Function to print the linked list
void printList(node* head) {
    node* temp = head;
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list iteratively
void reverseList(node** head) {
    node* prev = NULL;  // Previous pointer
    node* curr = *head; // Current pointer
      // Next pointer
    
    while (curr != NULL) {
        node * cn= curr->next;
          // Store the next node
        curr->next = prev;  // Reverse the current node's pointer
        prev = curr;        // Move the previous pointer to the current node
        curr = cn;        // Move the current pointer to the next node
    }
    *head = prev; // Update the head to the new first node
    printf("The list has been reversed.\n");
}

int main() {
    node* head = NULL; // Initialize the head of the linked list
    int choice, data;
    
    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Append Node\n");
        printf("2. Print List\n");
        printf("3. Reverse List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to append: ");
                scanf("%d", &data);
                appendNode(&head, data);
                break;
                
            case 2:
                printf("Current Linked List:\n");
                printList(head);
                break;
                
            case 3:
                reverseList(&head);
                break;
                
            case 4:
                printf("Exiting program.\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4); // Continue until user chooses to exit

    return 0;
}
