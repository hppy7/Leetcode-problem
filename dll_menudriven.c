#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
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
    newNode->left = temp;
    return head;
}

// Function to insert a node at a specific position in the list
struct Node* insertAtPosition(struct Node *head, int data, int position) {
    struct Node *newNode = createNode(data);
    if (position == 1) {
        newNode->right = head;
        if (head != NULL) {
            head->left = newNode;
        }
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
    if (temp->right != NULL) {
        temp->right->left = newNode;
    }
    temp->right = newNode;
    newNode->left = temp;
    return head;
}

// Function to delete a node with a given key
struct Node* deleteNode(struct Node *head, int key) {
    struct Node *temp = head;

    // If the head node itself holds the key
    if (temp != NULL && temp->data == key) {
        head = temp->right;
        if (head != NULL) {
            head->left = NULL;
        }
        free(temp);
        return head;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        temp = temp->right;
    }

    // If the key was not present in the list
    if (temp == NULL) {
        printf("Key not found.\n");
        return head;
    }

    // Unlink the node from the list
    if (temp->right != NULL) {
        temp->right->left = temp->left;
    }
    if (temp->left != NULL) {
        temp->left->right = temp->right;
    }
    free(temp);

    return head;
}

// Function to display the linked list from start to end
void displayForward(struct Node *head) {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->right;
    }
    printf("NULL\n");
}

// Function to display the linked list from end to start
void displayBackward(struct Node *head) {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    // Go to the last node
    while (temp->right != NULL) {
        temp = temp->right;
    }

    printf("Backward: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->left;
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
        printf("4. Display List Forward\n");
        printf("5. Display List Backward\n");
        printf("6. Exit\n");
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
                displayForward(head);
                break;
            case 5:
                displayBackward(head);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
