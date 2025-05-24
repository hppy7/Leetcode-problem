#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void linkedlisttraversal(struct node* ptr) {
    while (ptr != NULL) {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node* deletingfromend(struct node* head, int n) {
    int c = 0;
    struct node* ptr = head;

    // Step 1: Count the total number of nodes
    while (ptr != NULL) {
        c++;
        ptr = ptr->next;
    }

    // Calculate position to remove
    int del = c - n;

    // Edge case: If we need to remove the head node
    if (del == 0) {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    // Step 2: Traverse to the node before the one to be deleted
    ptr = head;
    for (int i = 1; i < del; i++) {
        ptr = ptr->next;
    }

    // Step 3: Delete the nth node from the end
    struct node* temp = ptr->next;
    ptr->next = temp->next;
    free(temp);

    return head;
}

int main() {
    int n;
    struct node *head;
    struct node *second;
    struct node *third;

    // Allocate memory for linked list nodes
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 8;
    second->next = third;

    third->data = 11;
    third->next = NULL;

    printf("\n\nLinked list before deletion:\n");
    linkedlisttraversal(head);

    printf("Enter the value of n: ");
    scanf("%d", &n);

    head = deletingfromend(head, n);

    printf("\n\nLinked list after deletion:\n");
    linkedlisttraversal(head);

    return 0;
}
