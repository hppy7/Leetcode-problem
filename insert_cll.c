#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} l;

l *insert(l *f, l *r) {
    int c;
    while (1) {
        l *p = (l *)malloc(sizeof(l));
        printf("Enter the data: ");
        scanf("%d", &p->data);

        if (f == NULL && r == NULL) {
            f = r = p;
            p->next = f;
        } else {
            r->next = p;
            r = p;       
            r->next = f;
        }

        printf("Do you want to continue 1/0: ");
        scanf("%d", &c);
        if (c == 0)
            break;
    }

    return f;
}

void display(l *f) {
    if (f == NULL) {
        printf("List is empty.\n");
        return;
    }

    l *temp = f;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != f);

    printf("(back to head)\n");
}
l *insertbnode(l *ptr)
{
    l *temp=ptr;
   // l *newnode=NULL;
    l *newnode=(l *)malloc(sizeof(l));
    printf("enter the data for the node : ");
    scanf("%d",&newnode->data);
       if (ptr == NULL) {
        newnode->next = newnode; 
        return newnode;      
    }
    while(temp->next!=ptr)
    {
    temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=ptr;
    return newnode;
}

int main() {
    l *front = NULL, *rear = NULL;

    front = insert(front, rear);
    printf("The circular linked list is:\n");
    display(front);
    front=insertbnode(front);
    display(front);
    return 0;
}
