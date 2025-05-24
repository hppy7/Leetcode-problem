#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
}l;

l *create();
void split(l*,l **,l**);
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

void display(l *p)
{
    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}

void split(l *p1,l **h1,l **h2)
{
    int info;
    printf("enter the info from where u want to split");
    scanf("%d",&info);
    *h1=p1;
    while(p1->data!=info)
    {
        p1=p1->next;
    }
    *h2=p1->next;
    p1->next=NULL;
}

int main()
{
    l *list1=NULL,*list2=NULL;
    l *p1=NULL;
    printf("1st linkedlist :");
    p1=create();
    display(p1);
    split(p1,&list1,&list2);
    printf("list 1 : ");
    display(list1);
    printf("\nList 2 :");
    display(list2);
    return 0;
}