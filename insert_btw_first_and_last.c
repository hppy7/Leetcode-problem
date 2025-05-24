#include<stdio.h>
#include<stdlib.h>
typedef struct dlist
{
    struct dlist *prev;
    int data;
    struct dlist *next;
}dl;

dl *dinsert(dl*);
dl *ddel(dl *);
void *insertfl(dl *);
void display(dl *);

void *insertfl(dl *f)
{
    dl *temp=f;
    dl *p=NULL;
    p=(dl *)malloc(sizeof(dl));
    printf("Enter the data :");
    scanf("%d",&p->data);
    p->next=temp->next;
    temp->next->prev=p->next;
    p->prev=temp;
    temp->next=p;
}

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

dl *ddel(dl*f)
{
    dl *p=NULL;
    printf("Deleted element is : %d\n",f->data);
    if(f==NULL)
    {
        printf("list is empty");
    }
    else{
        p=f;
        f=f->next;
        if(f==NULL)
        {
            free(p);
        }
        else
        {
        f->prev=NULL;
        free(p);
        }
    }
    return f;

}
void display(dl * f)
{
    if(f==NULL)
    {
        printf("Empty list..");
    }
    else{
        while(f!=NULL)
        {
            printf("%d\t",f->data);
            f=f->next;
        }
    }
}

int main()
{
    dl *f=NULL,*r=NULL;
    int ch;
    do 
    {
        printf("\n1.insert\n2.delete\n3.Insert between first and last\n4.display\n5.exit\n");
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
            f=ddel(f);
            if(f==NULL)
            {
                r=NULL;
            }
            break;
            case 3:
            insertfl(f);
            break;
            case 4:
            display(f);
            break;
            case 5:
            break;
        }
    }while(ch!=5);
    return 0;
}