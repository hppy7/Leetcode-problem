#include <stdio.h>
#define MAX 5

void push(int stack[], int *top) {
    int value;
    if (*top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter value to push: ");
    scanf("%d", &value);
    stack[++(*top)] = value;
    printf("Value pushed: %d\n", value);
}

void pop(int stack[], int *top) {
    if (*top < 0) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Value popped: %d\n", stack[(*top)--]);
}

void display(int stack[], int top) {
    if (top < 0) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int stack[MAX];
    int top = -1;
    int choice;

    do {
        printf("\nMenu:\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               
                push(stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
