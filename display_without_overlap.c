#include<stdio.h>
#include<stdlib.h>
typedef struct dlist
{
    struct dlist *prev;
    int data;
    struct dlist *next;
}dl;

dl *dinsert(dl*);
void display(dl *,dl *);

dl *dinsert(dl *r)
{
    dl *p=NULL;
    p=(dl*)malloc(sizeof(dl));
    printf("Enter the data :");
    scanf("%d",&p->data);
    if(r==NULL)
    {
        r=p;
        p->prev=NULL;
    }
    else{
        r->next=p;
        p->prev=r;
        r=p;
    }
    r->next=NULL;
    return r;
}

void display(dl * f,dl *r)
{
    int counter=0;
    int total;
    int s=0;
    dl *temp;
    temp=f;
    while(temp!=NULL)
    {
        counter++;
        temp=temp->next;
    }
    total=counter/2;
    if(f==NULL)
    {
        printf("Empty list..");
    }
    else{
        if(counter%2==0)
        {
        while(f!=r)
        {
            printf("%d\t",f->data);
            printf("%d\t",r->data);
            f=f->next;
            r=r->prev;
            s++;
            if(s==total)
            {
                exit(0);
            }
        }
        }
        else
        {
          while(f!=r)
        {
            printf("%d\t",f->data);
            printf("%d\t",r->data);
            f=f->next;
            r=r->prev;
            s++;
            if(s==total+1)
            {
                exit(0);
            }
        }
        }
    }
}

int main()
{
    dl *f=NULL,*r=NULL;
    int ch;
    do 
    {
        printf("\n1.insert\n2.delete\n3.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            r=dinsert(r);
            if(f==NULL)
            {
                f=r;
            }
            break;
            case 2:
            display(f,r);
            break;
            case 3:
            break;
        }
    }while(ch!=3);
    return 0;
}