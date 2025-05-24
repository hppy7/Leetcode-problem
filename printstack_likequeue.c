#include <stdio.h>

// Function to recursively print stack like a queue
void printStackLikeQueue(int* stack, int* top) {
    // Base case: if the stack is empty, return
    if (*top == -1) {
        return;
    }

    // Store the top element
    int top_element = stack[*top];

    // Move the pointer downwards (decrease top)9
    (*top)--;

    // Recursive call with the updated top pointer
    printStackLikeQueue(stack, top);

    // Print the element after the recursive call (in reverse order)
    printf("%d\n", top_element);
}

int main() {
    // Example stack with a fixed size
    int stack[5] = {1, 2, 3, 4, 5};
    int top = 4;  // The top points to the index of the last element (5)

    printf("Elements printed like a queue:\n");
    printStackLikeQueue(stack, &top);

    return 0;
}
