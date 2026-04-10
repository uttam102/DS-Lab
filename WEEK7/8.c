#include <stdio.h>
#define MAX 3
int stack[MAX], top = -1;
void push(int val) {
    if (top == MAX - 1) printf("Stack Overflow\n");
    else stack[++top] = val;
}
void pop() {
    if (top == -1) printf("Stack Underflow\n");
    else top--;
}
void display() {
    if (top == -1) printf("Empty\n");
    else for (int i = top; i >= 0; i--) printf("%d ", stack[i]);
    printf("\n");
}
int main() {
    int ch, val;
    do {
        scanf("%d", &ch);
        switch (ch) {
            case 1: scanf("%d", &val); push(val); break;
            case 2: pop(); break;
            case 3: display(); break;
        }
    } while (ch != 0);
}