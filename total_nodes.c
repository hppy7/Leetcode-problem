#include<stdio.h>
#include<stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} l;

l *insert(l *, l *);
void countnodes(l *,int *);
l *insert(l *f, l *r) {
    int c;
while(1)
{
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
    printf("Do you want to continue 1/0 :");
    scanf("%d",&c);
    if(c==0)
    break;
}

    return f; 
}

void countnodes(l *f,int *c) {
    l *temp = f;
    while (temp != NULL) {
            (*c)++;
        temp = temp->next;
    }
}

int main() {
    int count=0;
    l *f = NULL, *r = NULL; 
    f=insert(f,r);
    countnodes(f,&count);
    printf("Total Nodes are : %d",count);
    return 0;
}

