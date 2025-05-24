
//create a single list and detect a loop in single list
//floyds cycle detection

#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct list {
    int data;
    struct list *next;
} l;

// Function to create a new node and manage front and rear pointers
void create(l **front, l **rear) {
    l *new_node = (l *)malloc(sizeof(l));
    printf("Enter the data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (*front == NULL) {
        *front = *rear = new_node;  // If the list is empty, new node becomes the head and rear
    } else {
        (*rear)->next = new_node;    // Append the new node at the end
        *rear = new_node;            // Move rear to the new node
    }
    
}

// Function to detect a loop in the linked list using Floyd's Cycle Detection Algorithm
int detectLoop(l *head) {
    l *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;         // Move slow pointer by one step
        fast = fast->next->next;   // Move fast pointer by two steps

        if (slow == fast) {        // If slow and fast meet, loop is detected
            return 1;  // Loop detected
        }
    }
    return 0;  // No loop detected
}

// Function to find the starting node of the loop
l* findLoopStart(l *head) {
    l *slow = head, *fast = head;

    // First, check if a loop exists
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;// one step
        fast = fast->next->next; // two step

        // If there is a loop
        if (slow == fast) {
            // Move slow to the head
            slow = head;
            // Move both one step at a time; they will meet at the start of the loop
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;  // Return the starting node of the loop
        }
    }
    return NULL;  // No loop detected
}

// Function to print the linked list
void printList(l *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function to create the linked list and detect the loop
int main() {
    l *front = NULL, *rear = NULL;  // Pointers for the front and rear of the linked list
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create linked list\n");
        printf("2. Detect loop in the linked list\n");
        printf("3. Find starting node of the loop\n");
        printf("4. Display linked list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create(&front, &rear);
                break;
            case 2:
            (rear)->next=(front)->next->next; // there i connected last node to the the 3rd node of ll for creating a loop . 1,2,3,4,5  3 to5  is loop and 3 is starting point of loop
                if (detectLoop(front)) {
                    printf("Loop detected in the linked list!\n");
                } else {
                    printf("No loop detected in the linked list.\n");
                }
                break;
            case 3:
                if (detectLoop(front)) {
                    l *loopStart = findLoopStart(front);
                    printf("The starting node of the loop is: %d\n", loopStart->data);
                } else {
                    printf("No loop detected; cannot find starting node.\n");
                }
                break;
            case 4:
                printf("Linked List: ");
                printList(front);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
