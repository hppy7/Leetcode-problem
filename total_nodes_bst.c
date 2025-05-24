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
void  total_nodes(tree *,int *);
void  total_leaf_nodes(tree *,int *);
void  total_one_child_nodes(tree *,int *);

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
void total_nodes(tree *root,int *num) {
    if(root==NULL)
    {
        return ;
    }
    else{
        (*num)++;
        total_nodes(root->left,num);
        total_nodes(root->right,num);
    } 
}

void total_leaf_nodes(tree *root,int *num) {

    if(root==NULL)
    {
        return ;
    }
    else{
        if(root->left==NULL&&root->right==NULL){
        (*num)++;
        }
        total_leaf_nodes(root->left,num);
        total_leaf_nodes(root->right,num);
    }   
}

void total_one_child_nodes(tree *root,int *num) {
    if(root==NULL)
    {
        return ;
    }
    else{
        if(root->left==NULL&&root->right!=NULL||root->left!=NULL&&root->right==NULL){
        (*num)++;
        }
        total_one_child_nodes(root->left,num);
        total_one_child_nodes(root->right,num);
    }  
}


int main()
{
    int c;
    tree *root=NULL;
    int data;
    int choice ;
    do
    {
        printf("\n1.insert \n2.display\n3.total nodes\n 4.total leaf nodes \n5. total one child nodes \n6.exit\n");
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
            c=0;
            total_nodes(root,&c);
            printf("total nodes are : %d",c);
            break;
            case 4:
            c=0;
            total_leaf_nodes(root,&c);
            printf("Total leaf nodes are : %d",c);
            break;
            case 5:
            c=0;
            total_one_child_nodes(root,&c);
            printf("Total one child nodes are : %d",c);
            break;
            case 6:
            exit(0);

        }
    } while (choice!=6);
    
    return 0;
}