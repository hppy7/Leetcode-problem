#include<stdio.h>
#include<stdlib.h>
typedef struct clist
{
    int data;
    struct clist *next;
}cl;

cl *cenq(cl **f,cl **r)
{
    int ch;
    cl *p=NULL;

    p=(cl *)malloc(sizeof(cl));
    if(p==NULL)
    {
        printf("Memory Allocation failed..");
    }
    printf("Enter the data :");
    scanf("%d",&p->data);
    if(*f==NULL&&*r==NULL)
    {
        *f=*r=p;
    }
    else
    {
        (*r)->next=p;
        (*r)=p;
    }
    p->next=(*f);
}


cl *cdeq(cl **f,cl **r)
{
    cl *p=NULL;
    if(*f==NULL&&*r==NULL)
    {
        printf("circular queue is empty ");
    }
    else{
        p=*f;
        printf("%d is dequeued element \n",p->data);
        if(*f==*r)
        {
            *f=*r=NULL;
            free(p);
        }
        *f=(*f)->next;
        (*r)->next=*f;
    }
    free(p);
}
void display(cl *f)
{
    cl *p=f;
    if(f==NULL)
    printf("queue is Empty");
    do
    {
        printf("%d\t",p->data);
        p=p->next;
    }while (p!=f);

}
    
int main()
{
    cl *f=NULL,*r=NULL;
    int ch;
    do
    {
        printf("1.enqueue\n2.dequeu\n3.display.\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            cenq(&f,&r);
            break;
            case 2:
            cdeq(&f,&r);
            break;
            case 3:
            display(f);
            break;
            case 4:
            break;
        }
    } while(ch!=4);
    return 0;
    
}
