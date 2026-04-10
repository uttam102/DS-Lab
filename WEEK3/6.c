/*6. Factorial Using Function (Call by Value)
Calculate factorial using a function where the number is passed by value.*/
#include <stdio.h>
int factorial(int n) {
    int fact = 1, i;
    for(i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Factorial = %d\n", factorial(num));
    return 0;
}
