#include<stdio.h>
#include<stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} l;

l *insert(l *, l *);
void countnodes(l *);
l *insert(l *f, l *r) {
    l *p = (l *)malloc(sizeof(l));
    printf("Enter the data: ");
    scanf("%d", &p->data);
    p->next = NULL;

    if (f == NULL && r == NULL) {
        f = r = p;
    } else {
        r->next = p;
        r = p; 
    }

    return f; 
}

void countnodes(l *f) {
    l *temp = f;
    int c = 0;
    int key;
    printf("Enter the key: ");
    scanf("%d", &key);

    while (temp != NULL) {
        if (temp->data < key) {  
            c++;
        }
        temp = temp->next;
    }
    printf("Nodes less than the key are: %d\n", c);
}

int main() {
    int ch;
    l *f = NULL, *r = NULL;  

    do {
        printf("\n1. Input nodes\n2. Calculate nodes less than key\n3. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                f = insert(f, r);
                if (r == NULL) {
                    r = f;  
                }
                break;
            case 2:
                countnodes(f);
                break;
            case 3:
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (ch != 3);

    return 0;
}
