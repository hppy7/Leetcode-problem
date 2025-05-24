// //write a menu driven program to create a two single linked list and then create a third linked list  using alternate nodes of both linked list.
// //create a single list and detect a loop in single list


#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} l;

// Function prototypes
l* create(l *head);
void printList(l *head);
l* alternateMerge(l *f, l *f1);
l* create(l *head) {
    l *new_node = (l *)malloc(sizeof(l));
    printf("Enter the data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;
    }

    l *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    return head;
}

void printList(l *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to merge alternate nodes from two lists
l* alternateMerge(l *f, l *f1) {
    l *mergedHead = NULL;  // Head of the merged list
    l *mergedTail = NULL;  // Tail of the merged list

    int position = 1; // Position to track the node number (1st, 2nd, 3rd)

    while (f != NULL || f1 != NULL) {
        // Add node from the first list if we're on an odd position
        if (f != NULL && position % 2 != 0) {
            l *new_node = (l *)malloc(sizeof(l));
            new_node->data = f->data;
            new_node->next = NULL;

            if (mergedHead == NULL) {
                mergedHead = mergedTail = new_node;  // Initialize the merged list
            } else {
                mergedTail->next = new_node;  // Append to the merged list
                mergedTail = new_node;
            }

            f = f->next;  // Move to the next node in the first list
        }

        // Add node from the second list if we're on an odd position
        if (f1 != NULL && position % 2 != 0) {
            l *new_node = (l *)malloc(sizeof(l));
            new_node->data = f1->data;
            new_node->next = NULL;

            if (mergedHead == NULL) {
                mergedHead = mergedTail = new_node;  // Initialize the merged list
            } else {
                mergedTail->next = new_node;  // Append to the merged list
                mergedTail = new_node;
            }

            f1 = f1->next;  // Move to the next node in the second list
        }

        position++;  // Increment position (used to track node number and alternate)
    }

    return mergedHead;  // Return the merged list's head
}

int main() {
    l *f = NULL, *f1 = NULL, *merged = NULL;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create first linked list\n");
        printf("2. Create second linked list\n");
        printf("3. Merge alternate nodes of both linked lists\n");
        printf("4. Display first linked list\n");
        printf("5. Display second linked list\n");
        printf("6. Display merged linked list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                f = create(f);
                break;
            case 2:
                f1 = create(f1);
                break;
            case 3:
                merged = alternateMerge(f, f1);
                printf("Merged list created successfully!\n");
                break;
            case 4:
                printf("First Linked List: ");
                printList(f);
                break;
            case 5:
                printf("Second Linked List: ");
                printList(f1);
                break;
            case 6:
                printf("Merged Linked List: ");
                printList(merged);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

