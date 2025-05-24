#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};


void linkedlisttraversal(struct node* ptr)
{
    while(ptr!=NULL)
    {
        printf("Element : %d\n",ptr->data);
        ptr=ptr->next;
    }
 
}

//case 1 


struct node * insertbeginning(struct node* head , int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node ));
    ptr->next=head;
    ptr->data =data;
    return ptr;
}

//case 2 


struct node * insertatindex(struct node* head , int data,int index)
{
        struct node *ptr=(struct node *)malloc(sizeof(struct node ));
        struct node *p=head;
        int i=0;
        while(i!=index-1)
        {
            p=p->next;
            i++;
        }
        ptr->data=data;
        ptr->next=p->next;
        p->next=ptr;
        return head;
}

//case 3

struct node * insertatend(struct node * head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

//case 4


struct node * insertafternode(struct node *prevnode,struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;

    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return head;
}


int main()
{
    struct node *head;
    struct node *second;
    struct node *third;

    //allocate memory for linked list in heap
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    
    head->data=7;
    head->next=second;
   
    second->data=8;
    second->next=third;
    
    third->data=11;
    third->next=NULL;
    linkedlisttraversal(head);
    
   // head=insertbeginning(head,56);
   //head=insertatindex(head,45,1);
    //head=insertatend(head,98);
    head=insertafternode(second,head,101);
    printf("\n After insertion  : ");
    linkedlisttraversal(head);
    
    return 0;

}