#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

// Method 1


// void linkedlisttraversal(struct node* head)
// {
//     struct node *ptr=head;
//     while(ptr->next!=head)
//     {
//         printf("Element : %d\n",ptr->data);
//         ptr=ptr->next;
//     }
//     printf("Element : %d",ptr->data);
 
// }

// Method 2

void linkedlisttraversal(struct node* head)
{
    struct node *ptr=head;
do
    {
        printf("Element : %d\n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}


//case 1 


struct node * insertbeginning(struct node* head , int data)
{
    struct node *ptr=(struct node *)malloc(sizeof(struct node ));
    ptr->data =data;

    struct node *p=head->next;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    return ptr;
}


int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    //allocate memory for linked list in heap
    head=(struct node *)malloc(sizeof(struct node));
    second=(struct node *)malloc(sizeof(struct node));
    third=(struct node *)malloc(sizeof(struct node));
    fourth=(struct node *)malloc(sizeof(struct node));
    
    head->data=4;
    head->next=second;
   
    second->data=3;
    second->next=third;
    
    third->data=6;
    third->next=fourth;

    fourth->data=1;
    fourth->next=head;
    printf("Circular Linkedlist before insertion : \n");
    linkedlisttraversal(head);
    printf("Circular Linkedlist after insertion : \n");
    head=insertbeginning(head,54);
    linkedlisttraversal(head);
    return 0;

}