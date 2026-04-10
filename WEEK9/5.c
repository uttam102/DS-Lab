#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *front = NULL, *rear = NULL;

void enqueue(int x) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if (rear == NULL)
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d\n", x);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Dequeued %d\n", front->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}

void display() {
    if (front == NULL) {
        printf("Queue empty\n");
        return;
    }
    struct Node *t = front;
    printf("Queue: ");
    while (t != NULL) {
        printf("%d ", t->data);
        t = t->next;
    }
    printf("\nFront=%d Rear=%d\n", front->data, rear->data);
}

int main() {
    int ch, x;
    while (1) {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &ch);
        if (ch == 1) {
            printf("Enter number: ");
            scanf("%d", &x);
            enqueue(x);
        } else if (ch == 2) dequeue();
        else if (ch == 3) display();
        else if (ch == 4) break;
    }
    return 0;
}
