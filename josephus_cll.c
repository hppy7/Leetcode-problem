#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a circular linked list
Node* createCircularList(int n) {
    Node *head = NULL, *temp = NULL, *last = NULL;

    for (int i = 1; i <= n; i++) {
        temp = (Node *)malloc(sizeof(Node));
        temp->data = i;  // Assigning data to the node
        temp->next = head; // Link the new node to the head

        if (head == NULL) {
            head = temp; // Set the head to the first node
        } else {
            last->next = temp; // Link the last node to the new node
        }

        last = temp; // Update the last node
    }
    
    // Complete the circular link
    if (last != NULL) {
        last->next = head; // Last node points to the head
    }

    return head;
}

// Function to perform the Josephus elimination
int josephus(Node *head, int k) {
    Node *current = head;
    Node *prev = NULL;

    // Eliminate nodes until only one remains
    while (current->next != current) { // More than one node exists
        for (int count = 1; count < k; count++) {
            prev = current; // Keep track of the previous node
            current = current->next; // Move to the next node
        }
        
        // Eliminate the k-th node
        prev->next = current->next; // Bypass the current node
        printf("Eliminated: %d\n", current->data); // Display eliminated node
        free(current); // Free memory of the eliminated node
        current = prev->next; // Move to the next node
    }

    return current->data; // Return the last remaining node's data
}

int main() {
    int n, k;

    printf("Enter the number of people (n): ");
    scanf("%d", &n);
    printf("Enter the step count (k): ");
    scanf("%d", &k);

    Node *circularList = createCircularList(n);
    int lastPerson = josephus(circularList, k);
    
    printf("The position of the last remaining person is: %d\n", lastPerson);
    return 0;
}
