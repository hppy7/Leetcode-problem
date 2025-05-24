#include<stdio.h>
#include<stdlib.h>

// Node structure for the linked list
struct node {
    int data;
    struct node *next;
};

// Function for forward traversal
struct node* ftraversal(struct node* head) {
    struct node* ptr = head;
    while (ptr != NULL) {
        printf("%d\t", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return head;
}

// Function to get the length of the linked list
int lengthofll(struct node* head) {
    int c = 0;
    struct node* ptr = head;
    while (ptr != NULL) {
        c = c + 1;
        ptr = ptr->next;
    }
    printf("\n\nThere are %d nodes present in the linked list.\n", c);
    return c;
}

// Function to search and delete a node with a specific key
struct node* deleteNode(struct node* head, int key) {
    struct node *temp = head, *prev = NULL;

    // If the key is in the first node
    if (temp != NULL && temp->data == key) {
        head = temp->next;
        free(temp);
        return head;
    }

    // Traverse to find the key
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key is not found
    if (temp == NULL) {
        printf("Unsuccessful Search\n");
        return head;
    }

    // Remove the node from the list
    prev->next = temp->next;
    free(temp);
    return head;
}

int main() {
    struct node *head = NULL, *n1, *n2, *n3, *n4;

    // Creating nodes and linking them
    n1 = (struct node*)malloc(sizeof(struct node));
    n2 = (struct node*)malloc(sizeof(struct node));
    n3 = (struct node*)malloc(sizeof(struct node));
    n4 = (struct node*)malloc(sizeof(struct node));

    n1->data = 23;
    n1->next = n2;

    n2->data = 34;
    n2->next = n3;

    n3->data = 56;
    n3->next = n4;

    n4->data = 52;
    n4->next = NULL;

    head = n1;

    printf("Forward Traversing:\n");
    ftraversal(head);

    lengthofll(head);

    // Deleting a node with a specific key
    int key;
    printf("Enter key to delete: ");
    scanf("%d", &key);

    head = deleteNode(head, key);

    printf("Updated Linked List:\n");
    ftraversal(head);

    lengthofll(head);

    return 0;
}
