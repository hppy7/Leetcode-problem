#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *left;
    int data;
    struct node *right;
}tree;

void insert(tree**,int);
void display(tree*);

void insert(tree **root,int num)
{
    if((*root)==NULL)
    {
        (*root)=(tree *)malloc(sizeof(tree));
        (*root)->data=num;
        (*root)->left=NULL;
        (*root)->right=NULL;
    }
    else
    {
        if(num<(*root)->data)
        {
            insert(&((*root)->left),num); // in the (*root)->left there is NULL we are passing the adreess of it for new node 
        }
        else{
            insert(&((*root)->right),num);
        }
    }
}
void display(tree *root)
{
    if(root!=NULL)
    {
        display(root->left);
        printf("%d\t",root->data);
        display(root->right);
    }
}

int main()
{
    tree *root=NULL;
    int data;
    int choice ;
    do
    {
        printf("\n1.insert \n2.display\n3.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the data : ");
            scanf("%d",&data);
            insert(&root,data);
            break;
            case 2:
            display(root);
            break;
            case 3:
            exit(0);
        }
    } while (choice!=3);
    
    return 0;
}