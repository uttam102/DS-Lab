#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Header {
    int count;
    struct Node *next;
};
struct Header *head = NULL;

void insert(int x) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = head->next;
    head->next = newNode;
    head->count++;
}

void deleteFront() {
    if (head->next == NULL) {
        printf("Empty\n");
        return;
    }
    struct Node *temp = head->next;
    head->next = temp->next;
    free(temp);
    head->count--;
}

void display() {
    struct Node *t = head->next;
    printf("List (%d nodes): ", head->count);
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\n");
}

int main() {
    int ch, x;
    head = (struct Header*)malloc(sizeof(struct Header));
    head->count = 0;
    head->next = NULL;
    while (1) {
        printf("\n1.Insert 2.DeleteFront 3.Display 4.Exit\n");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter number: ");
            scanf("%d", &x);
            insert(x);
        } else if (ch == 2) deleteFront();
        else if (ch == 3) display();
        else if (ch == 4) break;
    }
    return 0;
}
