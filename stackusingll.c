#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int data;
    struct stack *next;
} s;



s* push(s*);
s* pop(s*);
void display(s*);
void peek(s*);


s* push(s *tp) {
    s *p = NULL;
    int value;
    p = (s*)malloc(sizeof(s));
    
    if (p == NULL) {
        printf("Memory allocation failed!...\n");
        return tp;  
    } else {
        printf("Enter the value to push into the stack: ");
        scanf("%d", &value);
        p->data = value;
        p->next = tp; 
        tp = p;       
    }
    return tp;
}


s* pop(s *tp) {
    s *p = NULL;
    if (tp == NULL) {
        printf("Stack is empty\n");
    } else {
        p = tp;
        printf("Popped value is %d\n", tp->data);
        tp = tp->next;  
        free(p);       
    }
    return tp;
}


void display(s *top) {
    if (top == NULL) {
        printf("Stack is empty..\n");
    } else {
        while (top != NULL) {
            printf("%d\t", top->data);
            top = top->next;
        }
        printf("NULL\n");
    }
}


void peek(s *t) {
    if (t == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Peeked element is: %d\n", t->data);
    }
}

int main() {
    s *top = NULL;
    int ch;
    do {
        printf("1. Push \n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                top = push(top);
                break;
            case 2:
                top = pop(top);
                break;
            case 3:
                display(top);
                break;
            case 4:
                peek(top);
                break;
            case 5:
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    } while (ch != 5);
    
    return 0;
}
