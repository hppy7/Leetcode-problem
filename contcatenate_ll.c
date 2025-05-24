#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
}l;

l *create();
l *concatenate(l*,l*);
void display(l*);
l *create()
{
    l *p,*q=NULL,*temp=NULL;
    int ch,data;
    while(1)
    {
    p=(l*)malloc(sizeof(l));
    if(p==NULL)
    {
        printf("Memory allocation failed..");
        break;
    }
    printf("Enter the data : ");
    scanf("%d",&p->data);
    p->next=NULL;
    if(q==NULL)
    {
        q=p;
    }
    else
    {
        temp->next=p;
    }
    temp=p;
    printf("Do you want to continue press 1 otherwise 0 : ");
    scanf("%d",&ch);
    if(ch==0)
    {
        break;
    }
}
    return q;
}

    l *concatenate(l *p, l *q) {
    if (p == NULL) return q;  // Handle case if first list is empty
    l *temp = p;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = q;
    return p;  // Return the head of the concatenated list

}

void display(l *p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}


int main()
{
    l *p1=NULL,*p2=NULL,*p3=NULL;
    printf("1st linkedlist :");
    p1=create();
    printf("2nd linked list :");
    p2=create();

    p3=concatenate(p1,p2);

    display(p3);
    return 0;
}

