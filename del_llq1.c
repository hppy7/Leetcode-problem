#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct Node {
    int data;
    struct Node *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->right = NULL;
    return newNode;
}

// Function to add a node at the end of the list
void append(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    temp->right = newNode;
}

// Function to delete a node with a given key
void deleteNode(Node **head, int key) {
    Node *temp = *head;
    Node *prev = NULL;

    // If the head node itself holds the key
    if (temp != NULL && temp->data == key) {
        *head = temp->right; // Change head
        free(temp); // Free old head
        printf("Element with key %d deleted.\n", key);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->right;
    }

    // If the key was not present in the list
    if (temp == NULL) {
        printf("Unsuccessful Search\n");
        return;
    }

    // Unlink the node from linked list
    prev->right = temp->right;
    free(temp); // Free memory
    printf("Element with key %d deleted.\n", key);
}

// Function to print the linked list
void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->right;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    int choice, data, key;

    while (1) {
        printf("1. Append node\n");
        printf("2. Delete node by key\n");
        printf("3. Print list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to append: ");
                scanf("%d", &data);
                append(&head, data);
                break;

            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteNode(&head, key);
                break;

            case 3:
                printList(head);
                break;

            case 4:
                // Free all nodes before exiting
                while (head != NULL) {
                    Node *temp = head;
                    head = head->right;
                    free(temp);
                }
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
