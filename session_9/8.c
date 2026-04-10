#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};
struct Node *head = NULL;

void insertPos(int x, int pos) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    if (head == NULL) {
        head = newNode;
        head->next = head;
        head->prev = head;
        return;
    }
    struct Node *t = head;
    if (pos == 1) {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
        return;
    }
    for (int i = 1; i < pos - 1; i++)
        t = t->next;
    newNode->next = t->next;
    newNode->prev = t;
    t->next->prev = newNode;
    t->next = newNode;
}

void deletePos(int pos) {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    struct Node *t = head;
    if (pos == 1) {
        t->prev->next = t->next;
        t->next->prev = t->prev;
        head = t->next;
        free(t);
        return;
    }
    for (int i = 1; i < pos; i++)
        t = t->next;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

void displayForward() {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    struct Node *t = head;
    printf("Forward: ");
    do {
        printf("%d ", t->data);
        t = t->next;
    } while (t != head);
    printf("\n");
}

void displayBackward() {
    if (head == NULL) return;
    struct Node *t = head->prev;
    printf("Backward: ");
    do {
        printf("%d ", t->data);
        t = t->prev;
    } while (t->next != head->prev);
    printf("\n");
}

int main() {
    int ch, x, pos;
    while (1) {
        printf("\n1.Insert 2.Delete 3.Forward 4.Backward 5.Exit\n");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter value and position: ");
            scanf("%d%d", &x, &pos);
            insertPos(x, pos);
        } else if (ch == 2) {
            printf("Enter position: ");
            scanf("%d", &pos);
            deletePos(pos);
        } else if (ch == 3) displayForward();
        else if (ch == 4) displayBackward();
        else if (ch == 5) break;
    }
    return 0;
}
