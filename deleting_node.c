#include<stdio.h>
#include<stdlib.h>

typedef struct list
{
    int data;
    struct list *next;
}l;

l *insert(l*,l*);
void deletingnode(l*p);
void display(l*);


l *insert(l *f, l *r) {
    int c;
while(1)
{
    l *p = (l *)malloc(sizeof(l));
    printf("Enter the data: ");
    scanf("%d", &p->data);
    p->next = NULL;

    if (f == NULL && r == NULL) {
        f = r = p;
    } else {
        r->next = p;
        r = p; 
    }
    printf("Do you want to continue 1/0 :");
    scanf("%d",&c);
    if(c==0)
    break;
}

    return f; 
}
void display(l *head)
{
    while(head!=NULL)
    {
        printf("%d\t",head->data);
        head=head->next;
    }
}

void deletingnode(l*p)
{
    int key;
    l *temp=NULL;
    printf("enter the node data you want to delete: ");
    scanf("%d",&key);
    while(p!=NULL&&p->next->data!=key)
    {
        p=p->next;
    }
    printf("%d",p->data);
    temp=p->next;
    p->next=temp->next;
    free(temp);
}


int main()
{
    l *f=NULL,*r=NULL;
    printf("first list \n");
    f=insert(f,r);

    printf("deleting NOde : ");
    deletingnode(f);
    printf("Aftert deleting : \n");
    display(f);
    return 0;
}