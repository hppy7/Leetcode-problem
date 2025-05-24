#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Tree;

Tree* createNode(int data) {
    Tree* newNode = (Tree*)malloc(sizeof(Tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Tree* insert(Tree* root) {
    int data;
    printf("Enter the value to insert: ");
    scanf("%d", &data);

    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left);
    } else if (data > root->data) {
        root->right = insert(root->right);
    }
    return root;
}

void inorderTraversal(Tree* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    Tree* root = NULL;
    int n, i;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        root = insert(root);
    }

    printf("In-order traversal of the binary search tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
