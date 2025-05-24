#include <stdio.h>
#include <stdlib.h>

void push(int *stack, int *top, int n, int value) {
    if (*top >= n - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++(*top)] = value;
    printf("Value pushed: %d\n", value);
}

void pop(int *stack, int *top) {
    if (*top < 0) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Value popped: %d\n", stack[(*top)--]);
}

void display(int *stack, int top) {
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
    int n;
    printf("Enter the fixed n of the stack: ");
    scanf("%d", &n);

    int *stack = (int *)malloc(n * sizeof(int));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int top = -1;
    int choice, value;

    do {
        printf("\nMenu:\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(stack, &top, n, value);
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

    free(stack);
    return 0;
}
