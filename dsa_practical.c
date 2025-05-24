#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
}l;

l *create()
{
    int ch;
    l *head=NULL;
    l *temp=NULL;
    while(1)
    {
        l * newnode=(l*)malloc(sizeof(l));
        printf("enter the data : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            temp->next=newnode;
        }
        temp=newnode;
        printf("Do you want to continue :  ");
        scanf("%d",&ch);
        if(ch==0)
        {
            break;
        }
    }
    return head;
}
l* da(l* ptr) {
    l* temp = ptr, *final = ptr;
    temp = temp->next;
    free(ptr);
    ptr = temp;
    final = ptr;

    //printf("%d\n", ptr->data);
    while(ptr->next != NULL) {
        temp = ptr->next;
        ptr->next = temp->next;
        free(temp);
        ptr = ptr->next;
    }

    return final;
}
void del_alternate(l *head)
{
    l *r= head;
    l *temp=NULL;
    while(head!=NULL)
    {
        temp=head->next;
        head->next=temp->next;
        free(temp);
        head=head->next;
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
    l * head=NULL;
    head=create();
    display(head);
    //del_alternate(head);
    head = da(head);
    display(head);
    return 0;
}