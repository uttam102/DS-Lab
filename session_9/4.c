#include <stdio.h>
#include <stdlib.h>

struct Poly {
    int coeff, exp;
    struct Poly *next;
};

struct Poly* create() {
    struct Poly *head = NULL, *temp = NULL, *newNode;
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        newNode = (struct Poly*)malloc(sizeof(struct Poly));
        printf("Enter coeff and exp: ");
        scanf("%d%d", &newNode->coeff, &newNode->exp);
        newNode->next = NULL;
        if (head == NULL) head = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

void display(struct Poly *p) {
    while (p != NULL) {
        printf("%dx^%d ", p->coeff, p->exp);
        p = p->next;
        if (p != NULL) printf("+ ");
    }
    printf("\n");
}

struct Poly* add(struct Poly *p1, struct Poly *p2) {
    struct Poly *p3 = NULL, *temp = NULL, *newNode;
    while (p1 != NULL || p2 != NULL) {
        newNode = (struct Poly*)malloc(sizeof(struct Poly));
        newNode->next = NULL;
        if (p2 == NULL || (p1 != NULL && p1->exp > p2->exp)) {
            newNode->coeff = p1->coeff;
            newNode->exp = p1->exp;
            p1 = p1->next;
        } else if (p1 == NULL || p2->exp > p1->exp) {
            newNode->coeff = p2->coeff;
            newNode->exp = p2->exp;
            p2 = p2->next;
        } else {
            newNode->coeff = p1->coeff + p2->coeff;
            newNode->exp = p1->exp;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p3 == NULL) p3 = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return p3;
}

int main() {
    struct Poly *p1, *p2, *p3;
    printf("Enter first polynomial\n");
    p1 = create();
    printf("Enter second polynomial\n");
    p2 = create();
    printf("First: "); display(p1);
    printf("Second: "); display(p2);
    p3 = add(p1, p2);
    printf("Sum: "); display(p3);
    return 0;
}
