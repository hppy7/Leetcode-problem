#include <stdio.h>
#define MAX 10

int deque[MAX];
int front = -1, rear = -1;

void insertFront(int item) {
    if (front == 0) {
        printf("Cannot insert at front. Front overflow.\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        front--;
    }
    deque[front] = item;
    printf("%d inserted at front\n", item);
}

void insertRear(int item) {
    if (rear == MAX - 1) {
        printf("Deque is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    deque[rear] = item;
    printf("%d inserted at rear\n", item);
}

void deleteFront() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deleted from front: %d\n", deque[front]);
    if (front == rear) {
        front = rear = -1; // deque becomes empty
    } else {
        front++;
    }
}

void display() {
    if (front == -1) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\n");
}

int main() {
    int choice, item;

    while (1) {
        printf("\nOutput-Restricted Deque Menu\n");
        printf("1. Insert at front\n");
        printf("2. Insert at rear\n");
        printf("3. Delete from front\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at front: ");
                scanf("%d", &item);
                insertFront(item);
                break;
            case 2:
                printf("Enter the element to insert at rear: ");
                scanf("%d", &item);
                insertRear(item);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
