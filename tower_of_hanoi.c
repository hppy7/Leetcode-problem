#include<stdio.h>
void tower(int,char,char,char);
void main()
{
    int n;
    char A,B,C;
    printf("enter the value of n");
    scanf("%d",&n);
    A='A';
    B='B';
    C='C';
    tower(n,A,B,C);
}
 void tower(int n,char A,char B,char C)
{
    if(n==1)
    {
        printf("Move disk 1 from %c to %c\n",A,C);
        return;
    }
    tower(n-1,C,B,A);
    printf("Move disk %d from %c to %c\n",n,B,C);
    tower(n-1,A,C,B);
}