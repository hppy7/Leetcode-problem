#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    int choice;
    printf("Where to insert %d?\n1. Left of %d\n2. Right of %d\n", data, root->data, root->data);
    printf("Enter your choice (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        root->left = insertNode(root->left, data);
    } else if (choice == 2) {
        root->right = insertNode(root->right, data);
    } else {
        printf("Invalid choice!\n");
    }

    return root;
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

typedef struct Queue {
    Node* nodes[MAX_QUEUE_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, Node* node) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->nodes[q->rear] = node;
}

Node* dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return NULL;
    }
    Node* temp = q->nodes[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return temp;
}

void levelOrder(Node* root) {
    if (root == NULL) return;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        Node* temp = dequeue(&q);
        printf("%d ", temp->data);

        if (temp->left != NULL) enqueue(&q, temp->left);
        if (temp->right != NULL) enqueue(&q, temp->right);
    }
}

void menu() {
    printf("\nMenu:\n");
    printf("1. Insert node\n");
    printf("2. Inorder traversal\n");
    printf("3. Preorder traversal\n");
    printf("4. Postorder traversal\n");
    printf("5. Level-order traversal\n");
    printf("6. Exit\n");
}

int main() {
    Node* root = NULL;
    int choice, data;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;

            case 2:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 4:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Level-order traversal: ");
                levelOrder(root);
                printf("\n");
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}
