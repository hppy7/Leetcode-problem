#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the priority queue using typedef
typedef struct node {
    int data;
    int priority;
    struct node* next;
} pq;  // Use typedef as pq

// Function to create a new node
pq* createNode(int data, int priority) {
    pq* newNode = (pq*)malloc(sizeof(pq));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an element into the priority queue (simple insertion at the front)
void enqueue(pq** head) {
    int data, priority;
    printf("Enter data: ");
    scanf("%d", &data);
    printf("Enter priority: ");
    scanf("%d", &priority);

    pq* newNode = createNode(data, priority);
    newNode->next = *head;
    *head = newNode;
}

// Function to remove the element with the highest priority (smallest priority number)
void dequeue(pq** head) {
    if (*head == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }

    // Find the node with the highest priority
    pq* temp = *head;
    pq* prev = NULL;
    pq* highest = *head; 
    pq* highestPrev = NULL;// it will be used to remove node

    while (temp != NULL) {
        if (temp->priority < highest->priority) {
            highest = temp;
            highestPrev = prev;
        }
        prev = temp;
        temp = temp->next;
    }

    // Remove the highest priority node
    if (highestPrev == NULL) {  // If the highest priority node is the head
        *head = highest->next;
    } else {
        highestPrev->next = highest->next;
    }

    printf("Dequeued element: %d with priority %d\n", highest->data, highest->priority);
    free(highest);
}

// Function to display the priority queue
void display(pq* head) {
    if (head == NULL) {
        printf("Priority Queue is empty.\n");
        return;
    }
    pq* current = head;
    printf("Priority Queue: ");
    while (current != NULL) {
        printf("%d(p%d) ", current->data, current->priority);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    pq* pqHead = NULL;  // Initialize the priority queue

    int choice;

    while (1) {
        printf("\nPriority Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue(&pqHead);
                break;
            case 2:
                dequeue(&pqHead);
                break;
            case 3:
                display(pqHead);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
