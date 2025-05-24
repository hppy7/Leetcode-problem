#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<math.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int evaluatePostfix(char* expression) {
    int i;
    for (i = 0; expression[i] != '\0'; i++) {
        // If the character is a digit, convert it to integer and push onto the stack
        if (isdigit(expression[i])) {
            push(expression[i] - '0'); // Convert char to int
        }
        // If the character is an operator, pop two elements and perform the operation
        else {
            int operand2 = pop();
            int operand1 = pop();
            int result;
            switch (expression[i]) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                case '%': result = operand1 % operand2; break;
                //case '^': result = pow(operand1 , operand2); break;
                default:
                    printf("Invalid operator encountered: %c\n", expression[i]);
                    exit(1);
            }
            push(result); // Push the result of the operation onto the stack
        }
    }
    return pop(); // The final result will be the only element left in the stack
}

int main() {
    char expression[MAX];
    printf("Enter a postfix expression: ");
    scanf("%s", expression);

    int result = evaluatePostfix(expression);
    printf("The result of the postfix expression is: %d\n", result);

    return 0;
}
