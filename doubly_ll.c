#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node * ftraversal(struct node * head)
{
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

struct node * lengthofll(struct node *head)
{
    int c=0;
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        c=c+1;
        ptr=ptr->next;
    }
    printf(" \n\nThere are %d nodes present in the linked list . ",c);
}
struct node * btraversal(struct node *taill)
{
    struct node *tail =taill;
    while(tail!=NULL)
    {
        printf("%d\t",tail->data);
        tail=tail->prev;
    }
}

int main()
{
    struct node *n1;
    struct node *n2;
    struct node *n3;
    struct node *n4;
    //allocate memory for linked list in heap
    //creation of nodes
    n1=(struct node *)malloc(sizeof(struct node));
    n2=(struct node *)malloc(sizeof(struct node));
    n3=(struct node *)malloc(sizeof(struct node));
    n4=(struct node *)malloc(sizeof(struct node));

    //linking of nodes

    n1->next=n2;
    n1->prev=NULL;
    n2->next=n3;
    n2->prev=n1;
    n3->next=n4;
    n3->prev=n2;
    n4->next=NULL;
    n4->prev=n3;

    n1->data=23;
    n2->data=34;
    n3->data=56;
    n4->data=52;
printf("forward traversing : \n");
    ftraversal(n1);
printf("backward traversing : \n");
    btraversal(n4);
lengthofll(n1);
    return 0;
}

    

    
