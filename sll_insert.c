#include <stdio.h>
#include <stdlib.h>

typedef struct ll {
    int data;
    struct ll *next;
} ll;

ll* createnode();
ll* insertbf(ll*);
ll* insertaf(ll*);
ll* insertbl(ll*);
ll* insertal(ll*);
void display(ll*);

ll* createnode() {
    ll *newNode = (ll*)malloc(sizeof(ll));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}

ll* insertbf(ll *head) {
    ll *newNode = createnode();
    if (newNode == NULL) return head; // If node creation fails, return the original list
    newNode->next = head; // New node points to current head
    return newNode; // New node becomes the new head
}

ll* insertaf(ll *head) {
    if (head == NULL) {
        printf("List is empty. Adding first node.\n");
        return createnode();
    }
    ll *newNode = createnode();
    if (newNode == NULL) return head; // If node creation fails, return the original list
    newNode->next = head->next;
    head->next = newNode; // Insert after the first node
    return head; // Head remains unchanged
}

ll* insertbl(ll *head) {
    if (head == NULL) {
        printf("List is empty. Adding first node.\n");
        return createnode();
    }
    ll *newNode = createnode();
    if (newNode == NULL) return head; // If node creation fails, return the original list
    if (head->next == NULL) { // Only one node in the list
        newNode->next = head;
        return newNode; // New node becomes the head
    }
    ll *temp = head;
    while (temp->next->next != NULL) temp = temp->next; // Find second-last node
    newNode->next = temp->next;
    temp->next = newNode; // Insert before last node
    return head;
}

ll* insertal(ll *head) {
    if (head == NULL) {
        printf("List is empty. Adding first node.\n");
        return createnode();
    }
    ll *newNode = createnode();
    if (newNode == NULL) return head; // If node creation fails, return the original list
    ll *temp = head;
    while (temp->next != NULL) temp = temp->next; // Find last node
    temp->next = newNode; // Insert after last node
    return head;
}

void display(ll *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    ll *temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    ll *head = NULL;
    int ch;
    do {
        printf("\n0. Create first node\n1. Insert before first node\n2. Insert after first node\n3. Insert before last node\n4. Insert after last node\n5. Display list\n6. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 0:
                head = createnode();
                break;
            case 1:
                head = insertbf(head);
                break;
            case 2:
                head = insertaf(head);
                break;
            case 3:
                head = insertbl(head);
                break;
            case 4:
                head = insertal(head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    } while (ch != 6);

    return 0;
}
