#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *top = NULL;

void push(int x) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    printf("Pushed %d\n", x);
}

void pop() {
    if (top == NULL) {
        printf("Stack empty\n");
        return;
    }
    printf("Popped %d\n", top->data);
    struct Node *temp = top;
    top = top->next;
    free(temp);
}

void peek() {
    if (top == NULL)
        printf("Stack empty\n");
    else
        printf("Top element = %d\n", top->data);
}

void display() {
    if (top == NULL) {
        printf("Stack empty\n");
        return;
    }
    struct Node *t = top;
    printf("Stack: ");
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter number: ");
            scanf("%d", &x);
            push(x);
        } else if (ch == 2) pop();
        else if (ch == 3) peek();
        else if (ch == 4) display();
        else if (ch == 5) break;
    }
    return 0;
}
