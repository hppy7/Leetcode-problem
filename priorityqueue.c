#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX * 2]; // Array to store elements and their priorities
int front = -1, rear = -1;

// Function to check if the queue is empty
int isEmpty() {
    return front == -1;
}

// Function to check if the queue is full
int isFull() {
    return rear == MAX * 2 - 2;
}

// Function to enqueue an element with its priority
void enqueue(int element, int priority) {
    if (isFull()) {
        printf("Queue is full!\n");
        return;
    }

    // If queue is empty, initialize front and rear
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear += 2;
    }
    
    queue[rear] = element;
    queue[rear + 1] = priority;

    printf("Enqueued element: %d with priority: %d\n", element, priority);
}

// Function to dequeue the highest priority element
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }

    // Find the index of the highest priority element
    int min = front;
    for (int i = front + 2; i <= rear; i += 2) {
        if (queue[i + 1] < queue[min + 1]) {
            min = i;
        }
    }

    printf("Dequeued element: %d with priority: %d\n", queue[min], queue[min + 1]);

    // Shift elements to fill the gap left by the dequeued element
    for (int i = min; i < rear; i += 2) {
        queue[i] = queue[i + 2];
        queue[i + 1] = queue[i + 3];
    }

    rear -= 2;

    // Reset front and rear if the queue is now empty
    if (rear < front) {
        front = rear = -1;
    }
}


void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements:\n");
    for (int i = front; i <= rear; i += 2) {
        printf("Element: %d, Priority: %d\n", queue[i], queue[i + 1]);
    }
}

int main() {
    int choice, element, priority;

    while (1) {
        printf("\nPriority Queue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                printf("Enter priority: ");
                scanf("%d", &priority);
                enqueue(element, priority);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
