#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void insertPos(int x, int pos) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    if (head == NULL) {
        head = newNode;
        head->next = head;
        return;
    }
    if (pos == 1) {
        struct Node *t = head;
        while (t->next != head)
            t = t->next;
        t->next = newNode;
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node *t = head;
    for (int i = 1; i < pos - 1 && t->next != head; i++)
        t = t->next;
    newNode->next = t->next;
    t->next = newNode;
}

void deletePos(int pos) {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node *t = head, *temp;
    if (pos == 1) {
        while (t->next != head)
            t = t->next;
        temp = head;
        head = head->next;
        t->next = head;
        free(temp);
        return;
    }
    for (int i = 1; i < pos - 1 && t->next != head; i++)
        t = t->next;
    temp = t->next;
    t->next = temp->next;
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("List empty\n");
        return;
    }
    struct Node *t = head;
    printf("Circular List: ");
    do {
        printf("%d ", t->data);
        t = t->next;
    } while (t != head);
    printf("\n");
}

int main() {
    int ch, x, pos;
    while (1) {
        printf("\n1.Insert 2.Delete 3.Display 4.Exit\n");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter value and position: ");
            scanf("%d%d", &x, &pos);
            insertPos(x, pos);
        } else if (ch == 2) {
            printf("Enter position: ");
            scanf("%d", &pos);
            deletePos(pos);
        } else if (ch == 3) display();
        else if (ch == 4) break;
    }
    return 0;
}
