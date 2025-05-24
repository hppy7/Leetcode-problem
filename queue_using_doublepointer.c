#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct queue {
    int data;
    struct queue *next;
} q;

// Function prototypes
void enqueue(q**, q**);
void dequeue(q**, q**);
void display(q*);

// Function to enqueue (insert) an element into the queue
void enqueue(q **front, q **rear) {
    q *newNode = (q*)malloc(sizeof(q));
    int value;
    if (newNode == NULL) {
        printf("Memory allocation failed!...\n");
        return;
    }
    printf("Enter the value to enqueue: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;
    
    if (*rear == NULL) {
        *front = *rear = newNode; // Both front and rear point to the new node
    } else {
        (*rear)->next = newNode; // Link new node at the end
        *rear = newNode;         // Update rear to the new node
    }
    printf("Enqueued %d\n", value);
}

// Function to dequeue (remove) an element from the queue
void dequeue(q **front, q **rear) {
    if (*front == NULL) {
        printf("Queue is empty, cannot dequeue.\n");
        return;
    }

    q *temp = *front;
    printf("Dequeued value is %d\n", temp->data);
    *front = (*front)->next;  // Move front to the next node

    if (*front == NULL) {
        *rear = NULL; // If queue becomes empty, set rear to NULL
    }
    free(temp);
}

// Function to display the elements in the queue
void display(q *front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        while (front != NULL) {
            printf("%d\t", front->data);
            front = front->next;
        }
        printf("NULL\n");
    }
}

int main() {
    q *front = NULL, *rear = NULL;
    int choice;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue(&front, &rear);
                break;
            case 2:
                dequeue(&front, &rear);
                break;
            case 3:
                display(front);
                break;
            case 4:
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    } while (choice != 4);
    return 0;
}