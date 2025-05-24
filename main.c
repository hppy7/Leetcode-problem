#include <stdio.h>

#define MAX_SIZE 100  // Define maximum size of the priority queue

void enqueue(int pq[], int *f, int *r) {
    if (*r == MAX_SIZE * 2 - 2) {  // Check if the queue is full
        printf("Queue is full.\n");
        return;
    }

    int element, prio;
    printf("Enter the element: ");
    scanf("%d", &element);
    printf("Enter the priority: ");
    scanf("%d", &prio);

    int i = *r;  // Start from the last element
    while (i >= *f && pq[i + 1] > prio) {
        pq[i + 2] = pq[i];      // Shift data
        pq[i + 3] = pq[i + 1];  // Shift priority
        i -= 2;
    }
    
    pq[i + 2] = element;  // Insert new element
    pq[i + 3] = prio;     // Insert its priority
    *r += 2;  // Update rear pointer

    if (*f == -1) {
        *f = 0;  // Update front pointer if this is the first element
    }
}

void display(int pq[], int f, int r) {
    if (f == -1) {
        printf("Queue is empty.\n");
        return;
    }
    
    for (int i = f; i <= r; i += 2) {
        printf("Data: %d Priority: %d\n", pq[i], pq[i + 1]);
    }
}

int main() {
    int pq[2 * MAX_SIZE];  // Array to hold both data and priority
    int f = -1, r = -1;  // Initialize front and rear pointers

    int numElements;
    printf("How many elements do you want to enqueue? ");
    scanf("%d", &numElements);

    for (int i = 0; i < numElements; i++) {
        enqueue(pq, &f, &r);
    }

    display(pq, f, r);  // Display elements 
