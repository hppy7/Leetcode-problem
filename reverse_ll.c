//What Happens During Non-Tail Recursion?
//Stack Frames: Each recursive call creates a new stack frame, holding its state until the function returns.
//Unwinding: Once the base case is reached, the recursion starts unwinding, and each function call resumes from where it left off.
//Order of Execution: The printf() statement executes in the reverse order of the recursive calls, producing a reverse order output of the linked list

#include<stdio.h>
#include<stdlib.h>

// Define the structure for a simple singly linked list node using typedef
typedef struct node {
    int data;               // Data stored in the node
    struct node *next;      // Pointer to the next node in the list
} node;

// Function to create a singly linked list
node *create() {
    node *head = NULL, *temp = NULL, *newNode;
    int ch;

    while (1) {
        newNode = (node *)malloc(sizeof(node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            break;
        }

        // Take input for the new node's data
        printf("Enter the data for the node: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;  // First node becomes the head
        } else {
            temp->next = newNode;  // Link the new node to the end of the list
        }
        temp = newNode;  // Move temp to the new node

        // Check if the user wants to add more nodes
        printf("Do you want to add another node? (1 for yes, 0 for no): ");
        scanf("%d", &ch);
        if (ch == 0) {
            break;
        }
    }
    return head;
}

// Function to display the linked list in normal order
void display(node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
        if (temp != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}

// Function to display the linked list in reverse order using non-tail recursion
void displayReverse(node *head) {
    if (head == NULL) {
        return;
    }
    displayReverse(head->next);  // Recursive call for the next node
    printf("%d\t", head->data);  // Print current node after recursive call returns
}

int main() {
    node *head = NULL;

    printf("Create a linked list:\n");
    head = create();

    printf("Linked list in normal order is:\n");
    display(head);

    printf("Linked list in reverse order is:\n");
    displayReverse(head);
    printf("\n");

    return 0;
}
