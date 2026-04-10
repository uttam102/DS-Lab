/*5. Sum of Two Numbers Using Functions
Write a user-defined function that takes two integers as parameters and
returns their sum.*/
#include <stdio.h>
int sum(int a, int b) {
    return a + b;
}
int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Sum = %d\n", sum(num1, num2));
    return 0;
}