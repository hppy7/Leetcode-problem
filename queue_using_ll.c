#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int data;
    struct queue *next;
}q;

q *f=NULL;
q *r=NULL;
void enqueue();
void dequeue();
void display();

void enqueue()
{
    q *newnode=(q*)malloc(sizeof(q));
    if(newnode==NULL)
    {
        printf("memory allocation failed\n");
        return;
    }
        printf("Enter the value to enqueue : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
    if(r==NULL)
    {
        f=r=newnode;
    }
    else
    {
        r->next=newnode;
        r=newnode;
    }
}

void dequeue()
{
    if(f==NULL)
    {
        printf("queue is empty\n");
        return;
    }
    q *temp=f;
        printf("dequeue element is : %d\n",f->data);
        f=f->next;
    if(f==NULL)
    {
        r=NULL;
    }
    free(temp);

}

void display()
{
    if(f==NULL)
    {
        printf("queue is Empty\n ");
        return;
    }
    q *temp=f;
    printf("queue elements are : ");
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main()
{
    int value;
    int ch;
    do
    {
        printf("1.Enqueue\n");
        printf("2.dequeue\n");
        printf("3.display\n");
        printf("4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            enqueue();
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            break;
            default:
            printf("invalid choice\n");
        }
    } while (ch!=4);
    
}
