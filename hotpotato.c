#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int front, rear, size;
    int items[MAX];
} Queue;

// Function to initialize the queue
void initializeQueue(Queue* q) {
    q->front = q->rear = -1;
    q->size = 0;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->size == 0;
}

// Function to add an element to the queue
void enqueue(Queue* q, int value) {
    if (q->size == MAX) {
        printf("Queue is full!\n");
        return;
    }
    if (q->rear == -1) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }
    q->items[q->rear] = value;
    q->size++;
}

// Function to remove an element from the queue
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        exit(1);
    }
    int value = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    q->size--;
    return value;
}

// Function to simulate the Hot Potato game
int hotPotato(int players[], int n, int passes) {
    Queue q;
    initializeQueue(&q);

    // Add all players to the queue
    for (int i = 0; i < n; i++) {
        enqueue(&q, players[i]);
    }

    // Simulate the game
    while (q.size > 1) {
        // Pass the potato `passes` times
        for (int i = 0; i < passes; i++) {
            int temp = dequeue(&q);
            enqueue(&q, temp);
        }
        // Eliminate the player holding the potato
        printf("Player %d is eliminated.\n", dequeue(&q));
    }

    // Return the winner
    return dequeue(&q);
}

int main() {
    int players[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(players) / sizeof(players[0]);
    int passes = 3;

    int winner = hotPotato(players, n, passes);
    printf("The winner is Player %d.\n", winner);

    return 0;
}
