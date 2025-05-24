#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
}l;

l *insert(l*,l*);
void multiply(l*p,l*q);
void display(l*);


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
void display(l *head)
{
    while(head!=NULL)
    {
        printf("%d\t",head->data);
        head=head->next;
    }
}

void multiply(l *p,l *q)
{
    int product;
    while(p!=NULL&&q!=NULL)
    {
        product=(p->data)*(q->data);
        printf("%d\t",product);
        p=p->next;
        q=q->next;
    }
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
        while(q!=NULL)
    {
        printf("%d\t",q->data);
        q=q->next;
    }
}

int main()
{
    l *f=NULL,*r=NULL;
    l *f1=NULL,*r1=NULL;
    printf("first list \n");
    f=insert(f,r);
    printf("second list \n");
    f1=insert(f1,r1);
    printf("MULtiplication of 1st and 2nd : ");
    multiply(f,f1);
    return 0;
}