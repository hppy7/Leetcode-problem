#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->right = NULL;
    return newNode;
}

// Function to add a node at the end of the list and return the updated head
struct Node* append(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node *temp = head;
    while (temp->right != NULL) {
        temp = temp->right;
    }
    temp->right = newNode;
    return head;
}

// Function to insert a node at a specific position in the list
struct Node* insertAtPosition(struct Node *head, int data, int position) {
    struct Node *newNode = createNode(data);
    if (position == 1) {
        newNode->right = head;
        return newNode;
    }
    struct Node *temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->right;
    }
    if (temp == NULL) {
        printf("Position out of bounds.\n");
        return head;
    }
    newNode->right = temp->right;
    temp->right = newNode;
    return head;
}

// Function to delete a node with a given key
struct Node* deleteNode(struct Node *head, int key) {
    struct Node *temp = head, *prev = NULL;

    // If the head node itself holds the key
    if (temp != NULL && temp->data == key) {
        head = temp->right; // Change head
        free(temp); // Free old head
        return head;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->right;
    }

    // If the key was not present in the list
    if (temp == NULL) {
        printf("Key not found.\n");
        return head;
    }

    // Unlink the node from the list
    prev->right = temp->right;
    free(temp);

    return head;
}

// Function to display the linked list
void display(struct Node *head) {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->right;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int choice, data, position, key;

    do {
        printf("\nMenu:\n");
        printf("1. Append Node\n");
        printf("2. Insert Node at Position\n");
        printf("3. Delete Node\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to append: ");
                scanf("%d", &data);
                head = append(head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                head = deleteNode(head, key);
                break;
            case 4:
                display(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
