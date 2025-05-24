#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
}l;

l *create();
void dissimilar(l*,l*);
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

void dissimilar(l* p, l* q) {
    l* q_start = q; // Store the starting position of q
    while (p != NULL) {
        int found = 0;
        q = q_start; // Reset q to the start for each p
        while (q != NULL) {
            if (p->data == q->data) {
                found = 1; // Mark as found if there is a match
                break;
            }
            q = q->next;
        }
        if (!found) { // If not found in the second list, print the data
            printf("%d ", p->data);
        }
        p = p->next;
    }
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
    l *p1=NULL,*p2=NULL;
    printf("1st linkedlist :");
    p1=create();
    display(p1);
    printf("2nd linked list :");
    p2=create();
    display(p2);

    dissimilar(p1,p2);
    return 0;
}


