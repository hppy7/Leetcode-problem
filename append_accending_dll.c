#include <stdio.h>
#include <stdlib.h>

typedef struct dlist {
    struct dlist *prev;
    int data;
    struct dlist *next;
} dl;

dl *dinsert(dl *front);
dl *ddel(dl *front);
void display(dl *front);

dl *dinsert(dl *front) {
    dl *p = NULL, *temp = front;
    p = (dl *)malloc(sizeof(dl));
    printf("Enter the data: ");
    scanf("%d", &p->data);

    // Case 1: Insert at the beginning (list is empty or new data is smaller)
    if (front == NULL || p->data < front->data) {
        p->next = front;
        p->prev = NULL;
        if (front != NULL) {
            front->prev = p;
        }
        return p;  // Update front to the new node
    }

    // Case 2: Insert by searching for the correct position
    while (temp->next != NULL && temp->next->data < p->data) {
        temp = temp->next;
    }

    // Insert at the end or in between
    p->next = temp->next;
    p->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = p;
    }
    temp->next = p;

    return front;  // front remains unchanged
}

dl *ddel(dl*f)
{
    dl *p=NULL;
    printf("Deleted element is : %d\n",f->data);
    if(f==NULL)
    {
        printf("list is empty");
    }
    else{
        p=f;
        f=f->next;
        if(f==NULL)
        {
            free(p);
        }
        else
        {
        f->prev=NULL;
        free(p);
        }
    }
    return f;

}
void display(dl *front) {
    if (front == NULL) {
        printf("Empty list.\n");
    } else {
        while (front != NULL) {
            printf("%d\t", front->data);
            front = front->next;
        }
        printf("\n");
    }
}

int main() {
    dl *front = NULL;
    int ch;
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                front = dinsert(front);
                break;
            case 2:
                front = ddel(front);
                break;
            case 3:
                display(front);
                break;
            case 4:
                break;
        }
    } while (ch != 4);

    return 0;
}
