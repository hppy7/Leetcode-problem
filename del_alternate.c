#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
}l;

l *insert_ll(l **,int);
void display(l *);


l *insert_ll(l **head, int data)
{
    l *p=NULL;
    l *temp=NULL;
    p =(l*)malloc(sizeof(l));
    p->data=data;
    p->next=NULL;
    if((*head)==NULL)
    {
       (*head)=p=temp;
    }
    else
    {
        temp->next=p;
        temp=p;
    }
}

void display(l *head)
{
    while(head!=NULL)
    {
        printf("%d\t",head->data);
        head=head->next;
    }
}

int main()
{
    l *head=NULL;
    int data,choice;
    do{
        printf("\n1.insert node\n2.display\n3.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the data . ");
            scanf("%d",&data);
            insert_ll(&head,data);
            break;
            case 2:
            display(head);
            break;
            case 3:
            printf("Exiting..");
            break;

        }
    }while(choice!=3);
return 0;
}