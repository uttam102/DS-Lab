//2. Recursive Function for Fibonacci Series
//Generate the Fibonacci sequence using a recursive function.


#include <stdio.h>


int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);// Recursive call
}

int main() {
    int count, i;
    printf("Enter the number of terms: ");
    scanf("%d", &count);

    if (count < 0) {
        printf("Please enter a non-negative number.\n");
    } else {
        printf("Fibonacci Series: ");
        for (i = 0; i < count; i++) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }

    return 0;
}