/*8. Find Largest Among Three Numbers
Use nested if...else to determine the largest among three given numbers.*/

#include <stdio.h>

int main() {
    int a, b, c;
    printf("Find the largest among three numbers\n");
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("Enter third number: ");
    scanf("%d", &c);
    printf("You entered: %d, %d, %d\n", a, b, c);

    if (a > b) {
        if (a > c) {
            printf("%d is the largest.\n", a);
        } else {
            printf("%d is the largest.\n", c);
        }
    } else {
        if (b > c) {
            printf("%d is the largest.\n", b);
        } else {
            printf("%d is the largest.\n", c);
        }
    }

    return 0;
}
//gcc 8.c -o 8.exe
//.\8.exe