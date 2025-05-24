#include<stdio.h>
#include<stdlib.h>




typedef struct node {
    int data ;
    struct node *next;
}l;

l *createll(l *);
void display(l *);
void alternate_nodes(l *);
l *delete_alternate_nodes(l*);

l *createll(l *head)
{
    int ch;
    l *temp=head;
    while(1)
    {
        l *newnode =NULL;
        newnode=(l*)malloc(sizeof(l));

        printf("enter the value want to insert : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("Do you want to continue (1/0) : ");
        scanf("%d",&ch);
        if(ch==0)
        {
            break;
        }
    }
    return head;
}


void alternate_nodes(l *head )
{
    while(head!=NULL)
    {
        printf("%d\t",head->data);
        head=head->next->next;
    }
}

l *delete_alternate_nodes(l *head)
{
   
    l *t=NULL;
    l * te=NULL;
    te=head;
    head=head->next;
    l *temp=head;
    free(te);

    while(temp->next!=NULL)
    {
        
       t=temp->next;
       temp->next=t->next;
       free(t);
       temp=temp->next; 
    }
    return head;
}
void display(l *head)
{
    while(head!=NULL)
    {
        printf("%d\t",head->data);
        head=head->next;
    }
    return;
}

int main()
{
    l *left=NULL;
    left=createll(left);
    display(left);
    // printf("Alternate nodes : ");
    // alternate_nodes(left);
    printf("After deleting alternate nodes : ");
    left = delete_alternate_nodes(left);
    display(left);
    return 0;
}