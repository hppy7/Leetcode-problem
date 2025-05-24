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


struct node * deletebeginning(struct node* head )
{
   struct node *ptr=(struct node *)malloc(sizeof(struct node ));
    ptr = head;
    head =head->next;
    free(ptr);
    return head;
}

//case 2 


struct node * deleteatindex(struct node* head ,int index)
{
        struct node *p=head;
        int i=0;
        while(i!=index-1)
        {
            p=p->next;
            i++;
        }
        struct node *q=p->next;
        p->next=q->next;
        free(q);
        return head;
}

//case 3

struct node * deleteatend(struct node * head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    struct node *q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;

    }
    p->next=NULL;
    free(q);
    return head;
}

//case 4


struct node * deleteafternode(struct node *head,int value)
{
   // struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    struct node *q=head->next;
    while(q->data!=value && q->next!=NULL)
    {
        p=p->next;
        q=q->next;

    }
    if(q->data == value)
    {
       p->next=q->next;
       free(q); 
    }
    free(q);
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
    printf("\n\nlinked list before deletion : \n");
    linkedlisttraversal(head);
    head=deleteafternode(head,11);
    printf("\n\nlinked list After deleteion  : \n");
    linkedlisttraversal(head);
    
    return 0;

}