#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} n;

n* insert(n* head, int data) {
    n* newnode = (n*)malloc(sizeof(n));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        return newnode;
    }

    n* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

void display(n* head) {
    if (head == NULL) {
        printf("Linked list is empty.\n");
        return;
    }
    while (head != NULL) {
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("\n");
}

n* postive_ll(n* head) {
    n* pos = NULL;
    n* temp = NULL;

    while (head != NULL) {
        if (head->data >= 0) {
            n* newnode = (n*)malloc(sizeof(n));
            newnode->data = head->data;
            newnode->next = NULL;

            if (pos == NULL) {
                pos = newnode;  // First node in the positive list
                temp = newnode; // Temp points to the last node
            } else {
                temp->next = newnode; // Add to the end of the list
                temp = newnode;      // Update temp to the new last node
            }
        }
        head = head->next;
    }

    return pos;
}

n* negative_ll(n* head) {
    n* neg = NULL;
    n* temp = NULL;

    while (head != NULL) {
        if (head->data < 0) {
            n* newnode = (n*)malloc(sizeof(n));
            newnode->data = head->data;
            newnode->next = NULL;

            if (neg == NULL) {
                neg = newnode;  // First node in the negative list
                temp = newnode; // Temp points to the last node
            } else {
                temp->next = newnode; // Add to the end of the list
                temp = newnode;      // Update temp to the new last node
            }
        }
        head = head->next;
    }

    return neg;
}

int main() {
    n* head = NULL;
    n* pos = NULL;
    n* neg = NULL;
    int data, choice;

    do {
        printf("\nMenu:\n");
        printf("1. Insert node\n");
        printf("2. Print linked list\n");
        printf("3. Positive linked list\n");
        printf("4. Negative linked list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data for the node: ");
                scanf("%d", &data);
                head = insert(head, data);
                break;
            case 2:
                printf("Original Linked List: ");
                display(head);
                break;
            case 3:
                pos = postive_ll(head);
                printf("Positive Linked List: ");
                display(pos);
                break;
            case 4:
                neg = negative_ll(head);
                printf("Negative Linked List: ");
                display(neg);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
