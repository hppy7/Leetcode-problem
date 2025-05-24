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
    return 0;

}