#include <stdio.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;
void enqueue(int val) {
    if (rear == MAX - 1) printf("Overflow\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = val;
    }
}
void dequeue() {
    if (front == -1 || front > rear) printf("Underflow\n");
    else front++;
}
void display() {
    if (front == -1 || front > rear) printf("Empty\n");
    else for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
    printf("\n");
}
int main() {
    int ch, val;
    do {
        scanf("%d", &ch);
        switch (ch) {
            case 1: scanf("%d", &val); enqueue(val); break;
            case 2: dequeue(); break;
            case 3: display(); break;
        }
    } while (ch != 0);
}