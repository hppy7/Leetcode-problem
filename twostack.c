#include <stdio.h>
#define MAX 20

int array[MAX];  // Declaration of array type variable
int top1 = -1;   // Top pointer for Stack 1
int top2 = MAX;  // Top pointer for Stack 2

// Function to push data into stack1
void push1(int data) {
    if (top1 < top2 - 1) {
        top1++;
        array[top1] = data;
        printf("%d pushed to Stack 1\n", data);
    } else {
        printf("Stack 1 is full\n");
    }
}

// Function to push data into stack2
void push2(int data) {
    if (top1 < top2 - 1) {
        top2--;
        array[top2] = data;
        printf("%d pushed to Stack 2\n", data);
    } else {
        printf("Stack 2 is full\n");
    }
}

// Function to pop data from Stack1
void pop1() {
    if (top1 >= 0) {
        int popped_element = array[top1];
        top1--;
        printf("%d popped from Stack 1\n", popped_element);
    } else {
        printf("Stack 1 is empty\n");
    }
}

// Function to pop data from Stack2
void pop2() {
    if (top2 < MAX) {
        int popped_element = array[top2];
        top2++;
        printf("%d popped from Stack 2\n", popped_element);
    } else {
        printf("Stack 2 is empty\n");
    }
}

// Function to display the values of Stack1
void display_stack1() {
    if (top1 >= 0) {
        printf("Stack 1 elements: ");
        for (int i = top1; i >= 0; --i) {
            printf("%d ", array[i]);
        }
        printf("\n");
    } else {
        printf("Stack 1 is empty\n");
    }
}

// Function to display the values of Stack2
void display_stack2() {
    if (top2 < MAX) {
        printf("Stack 2 elements: ");
        for (int i = top2; i < MAX; ++i) {
            printf("%d ", array[i]);
        }
        printf("\n");
    } else {
        printf("Stack 2 is empty\n");
    }
}

int main() {
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Display Stack 1\n");
        printf("6. Display Stack 2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push to Stack 1: ");
                scanf("%d", &value);
                push1(value);
                break;
            case 2:
                printf("Enter value to push to Stack 2: ");
                scanf("%d", &value);
                push2(value);
                break;
            case 3:
                pop1();
                break;
            case 4:
                pop2();
                break;
            case 5:
                display_stack1();
                break;
            case 6:
                display_stack2();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}
