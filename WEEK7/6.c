#include <stdio.h>
#define SIZE 50
char stack[SIZE];
int top = -1;

void push(char c) {
    stack[++top] = c;
}
char pop() {
    return stack[top--];
}
int isMatching(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

int main() {
    char exp[SIZE];
    int i, flag = 1;
    char ch;

    printf("Enter an expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];

        if (ch == '(' || ch == '{' || ch == '[')
            push(ch);
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (top == -1 || !isMatching(stack[top], ch)) {
                flag = 0;
                break;
            } else {
                pop();
            }
        }
    }

    if (flag && top == -1)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
