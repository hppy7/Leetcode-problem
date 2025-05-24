#include<stdio.h>
#include<stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} l;

l *insert(l *, l *); 
l *delete2ndlast(l *);
void display(l *);

l *insert(l *f, l *r) {
    l *p = (l *)malloc(sizeof(l));  // Create a new node
    printf("Enter the data: ");
    scanf("%d", &p->data);
    p->next = NULL;

    if (f == NULL) {  // If the list is empty
        f = p;        // Set the first node
    } else {
        r->next = p;  // Append the node to the end of the list
    }
    
    return p;  // Return the new rear (last) node
}

l *delete2ndlast(l *f) {
    if (f == NULL || f->next == NULL) {
        printf("Not enough nodes to delete the second last node.\n");
        return f;
    }

    l *p = f;

    // Special case: if there are exactly two nodes
    if (p->next->next == NULL) {
        // We are deleting the first node (which is second last in this case)
        l *temp = p;
        f = p->next;  // Move the front to the second node
        printf("Node deleted is %d\n", temp->data);
        free(temp);
        return f;
    }

    // Traverse to the node just before the second last node
    while (p->next->next->next!= NULL) {
        p = p->next;
    }

    l *temp = p->next;  // The second last node
    p->next = temp->next;  // Skip over the second last node
    printf("Node deleted is %d\n", temp->data);
    free(temp);

    return f;  // Return updated front pointer
}

void display(l *f) {
    if (f == NULL) {
        printf("The list is empty.\n");
        return;
    }

    l *temp = f;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int ch;
    l *f = NULL, *r = NULL;  // Initialize front and rear pointers

    do {
        printf("\n1. Input nodes\n2. Delete 2nd last node\n3. Display \n4. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                r = insert(f, r);  // Insert a node
                if (f == NULL) {   // If the list was empty, set front to the new node
                    f = r;
                }
                break;
            case 2:
                f = delete2ndlast(f);  // Delete the second last node
                break;
            case 3:
                display(f);  // Display the list
                break;
            case 4:
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 4);

    return 0;
}
