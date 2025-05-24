#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    struct node *left;
    int data;
    struct node *right;
} tree;

void insert(tree **, int);
tree *delete_node(tree *, int);
tree *find_min(tree *);
void display(tree *);

void insert(tree **root, int num) {
    if (*root == NULL) {
        *root = (tree *)malloc(sizeof(tree));
        (*root)->data = num;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else if (num < (*root)->data) {
        insert(&((*root)->left), num);
    } else {
        insert(&((*root)->right), num);
    }
}

tree *find_and_delete(tree *root, int key) {
    if (root == NULL) {
        return root;
    }
    
    if (key < root->data) {
        root->left = find_and_delete(root->left, key);
    } else if (key > root->data) {
        root->right = find_and_delete(root->right, key);
    } else {
        // Node found
        if (root->left == NULL && root->right == NULL) {
            // Case 1: No children
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            // Case 2: One child (right child)
            tree *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            // Case 2: One child (left child)
            tree *temp = root->left;
            free(root);
            return temp;
        } else {
            // Case 3: Two children
            tree *temp = find_min(root->right);
            root->data = temp->data;
            root->right = find_and_delete(root->right, temp->data);
        }
    }
    return root;
}

tree *find_min(tree *root) {
    while (root->left != NULL) 
    root = root->left;
    return root;
}

void display(tree *root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

int main() {
    int choice, data;
    tree *root = NULL;

    do {
        printf("\n1. Insert\n2. Display\n3. Delete\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insert(&root, data);
                break;
            case 2:
                printf("In-order traversal: ");
                display(root);
                printf("\n");
                break;
            case 3:
                printf("Enter the data to delete: ");
                scanf("%d", &data);
                root = find_and_delete(root, data);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
