#include<stdio.h>
#include<stdlib.h>

typedef struct poly {
    int coeff;
    int expo;
    struct poly *next;
} poly;

poly *create() {
    poly *head = NULL, *temp = NULL, *newNode;
    int ch;

    while (1) {
        newNode = (poly *)malloc(sizeof(poly));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            break;
        }

        printf("Enter the coefficient for node: ");
        scanf("%d", &newNode->coeff);
        printf("Enter the exponent for node: ");
        scanf("%d", &newNode->expo);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode; 
        }
        temp = newNode; 

       
        printf("Do you want to add another term? (1 for yes, 0 for no): ");
        scanf("%d", &ch);
        if (ch == 0) {
            break;
        }
    }
    return head;
}


poly *addpoly(poly *p1, poly *p2) {
    poly *p3 = NULL, *temp = NULL, *newNode;

    while (p1 != NULL && p2 != NULL) {
        newNode = (poly *)malloc(sizeof(poly));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            break;
        }
        newNode->next = NULL;

        if (p1->expo == p2->expo) { 
            newNode->coeff = p1->coeff + p2->coeff;
            newNode->expo = p1->expo;
            p1 = p1->next;
            p2 = p2->next;
        } else if (p1->expo > p2->expo) {
            newNode->coeff = p1->coeff;
            newNode->expo = p1->expo;
            p1 = p1->next;
        } else { 
            newNode->coeff = p2->coeff;
            newNode->expo = p2->expo;
            p2 = p2->next;
        }

        if (p3 == NULL) {
            p3 = newNode; 
        } else {
            temp->next = newNode; 
        }
        temp = newNode; 
    }

 
    while (p1 != NULL) {
        newNode = (poly *)malloc(sizeof(poly));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            break;
        }
        newNode->coeff = p1->coeff;
        newNode->expo = p1->expo;
        newNode->next = NULL;

        if (p3 == NULL) {
            p3 = newNode;
            
        } else {
            temp->next = newNode;
        }
        temp = newNode;
        p1 = p1->next;
    }

    while (p2 != NULL) {
        newNode = (poly *)malloc(sizeof(poly));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            break;
        }
        newNode->coeff = p2->coeff;
        newNode->expo = p2->expo;
        newNode->next = NULL;

        if (p3 == NULL) {
            p3 = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
        p2 = p2->next;
    }

    return p3;
}


void display(poly *p) {
    if (p == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    while (p != NULL) {
        printf("%dx^%d", p->coeff, p->expo);
        p = p->next;
        if (p != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    poly *p1 = NULL, *p2 = NULL, *p3 = NULL;

    printf("Create first polynomial:\n");
    p1 = create();

    printf("Create second polynomial:\n");
    p2 = create();

    printf("Adding polynomials...\n");
    p3 = addpoly(p1, p2);

    printf("Resultant polynomial is:\n");
    display(p3);

    return 0;
}
