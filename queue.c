#include<stdio.h>
#define MAX 10
int enq(int [],int,int);
int dq(int[],int,int);
void dis(int[],int,int);
void peek(int[],int);
int main()
{
    int q[MAX];
    int f=-1,r=-1;
    int ch;
    do
    {
        printf("\n1.enqueue\n2.dequeue\n3.display\n4.peek\n5.exiting\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                r=enq(q,f,r);
                if(f==-1)
                f=0;
                break;
            case 2:
                f=dq(q,f,r);
                if(f==-1)
                r=-1;
                break;
            case 3:
                dis(q,f,r);
                break;
            case 4:
                peek(q,f);
                break;
            default:
                printf("exiting");
                break;
        }
    }while(ch<5);
    return 0;
}

int enq(int q[MAX],int f,int r)
{
    int x;
    if(f==MAX-1)
    printf("queue is full");
    else{
        printf("enter the value you want to insert ");
        scanf("%d",&x);
        r++;
        q[r]=x;
    }
    return r;
}

int dq(int q[MAX],int f,int r)
{   
    int x;
    if(f==-1&&r==-1)
    {
        printf("queue is empty");
    }
    else{
        x=q[f];
        printf("dequeued value is %d ", q[f]);
        if(f==r)
            f=-1;
        else
         {  f++;
            }   
    }
    return f;
}

void dis(int q[MAX],int f,int r)
{
     if(f==-1&&r==-1)
    {
        printf("queue is empty");
    }
    else
    {
        while(f!=r)
        {
            printf("%d\n",q[f]);
            f++;
        }
        printf("%d",q[f]);
    }
}

void peek(int q[MAX],int f)
{
     if(f==-1)
    {
        printf("queue is empty");
    }
    else{
        printf("peeked value is %d ", q[f]);
    }
}