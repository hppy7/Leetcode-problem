//wa c p to create sll by inserting nodes in such a way that resultant ll is in acending order 

#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
}l;

l *create_asc(l *, l *);
void display(l *);


l *create_asc(l *f,l *r)
{
    int ch;
    while(1)
    {
        l *p=NULL;
        p=(l*)malloc(sizeof(l));
        printf("Enter the data: ");
        scanf("%d",&p->data);
        p->next=NULL;
        if(f==NULL)
        {
            f=r=p;
        }
        else
        {
            if(p->data<f->data)
            {
                p->next=f;
                f=p;
            }
            else if(p->data>r->data){
                r->next=p;
                r=p;
            
            }
            else
            {
                l *temp = f;  // Start from the head
                // Find the correct position to insert
                while (temp->next != NULL && temp->next->data < p->data) {
                    temp = temp->next;
                }
                p->next = temp->next;
                temp->next = p;
            }
            }
    
        printf("Do you want to continue 0/1 :");
        scanf("%d",&ch);
        if(ch==0)
        {
            break;
        }
    }
    return f;
}

void display(l *f)
{
    while(f!=NULL)
    {
        printf("%d\t",f->data);
        f=f->next;
    }
}
int main()
{
    l *f=NULL,*r=NULL;
    f=create_asc(f,r);
    display(f);
    return 0;
}