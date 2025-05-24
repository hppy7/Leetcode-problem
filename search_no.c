#include<stdio.h>
#include<stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} l;

l *insert(l *, l *);
void search(l *,int,int * );
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
void search(l *f,int no,int *flag)
{
    while(f!=NULL)
    {
        if((f->data)==no)
        {
           (*flag)=1;
            break;
        }
        else{
            (*flag)=0;
        }
        f=f->next;
    }
}

int main()
{
    int no;
    int flag=0;
    l *f=NULL,*r=NULL;
    f=insert(f,r);
    printf("Enter the no to search : ");
    scanf("%d",&no);
    search(f,no,&flag);
    if(flag==0)
    {
        printf("Entered no is not in linked list .");
    }
    else{
        printf("Entered no is present in linked list.");
    }
    return 0;
}