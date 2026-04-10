#include <stdio.h>
#include <ctype.h>

#define SIZE 50
int stack[SIZE];
int top = -1;

void push(int value) {
    stack[++top] = value;
}
int pop() {
    return stack[top--];
}
int evaluatePostfix(char exp[]) {
    int i;
    char ch;
    int a, b;

    for (i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];

        if (isdigit(ch)) {
            push(ch - '0'); 
        } else {
            b = pop();
            a = pop();
            switch (ch) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
        }
    }
    return pop();
}
int main() {
    char exp[SIZE];
    printf("Enter postfix expression: ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result = %d\n", result);

    return 0;
}