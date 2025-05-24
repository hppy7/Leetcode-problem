#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 1000

// Stack operations using arrays
char stack[MAX_SIZE];
int top = -1;


// Initialize stack (not necessary since top is already initialized)
void initStack() {
    top = -1;
}

// Check if stack is empty
bool isEmpty() {
    return top == -1;
}

// Check if stack is full
bool isFull() {
    return top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(char c) {
    if (isFull()) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

// Pop an element from the stack
char pop() {
    if (isEmpty()) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[top--];
}

// Function to check if the input string is a valid parenthesis
bool isValidParenthesis(char *s) {
    initStack();

    for (int i = 0; s[i] != '\0'; i++) {
        char currentChar = s[i];

        if (currentChar == '(' || currentChar == '{' || currentChar == '[') {
            push(currentChar);
        } 
        else {
            if (isEmpty()) {
                return false;
            }
            char topChar = pop();
            if ((currentChar == ')' && topChar != '(') ||
                (currentChar == '}' && topChar != '{') ||
                (currentChar == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    return isEmpty();
}

// Main function to test the isValidParenthesis function
int main() {
    char input[MAX_SIZE];
    printf("Enter a string of parentheses: ");
    scanf("%s", input);

    if (isValidParenthesis(input)) {
        printf("The string is valid.\n");
    } else {
        printf("The string is not valid.\n");
    }

    return 0;
}