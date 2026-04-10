/*4. Operator Precedence Demonstration
Demonstrate arithmetic, relational, and logical operators in a single
expression and explain precedence.*/

#include <stdio.h>

int main() {
    int a = 20, b = 5, c = 0;

    // Arithmetic, Relational, and Logical Operators
    c = (a + b) * 2 > 15 && a < 10;
    // 0 = ( 20 + 5 ) *2 > 15 && 15 < 10
    // 0 = 50 > 15 && 20 < 10
    // 0 = 1 && 0
    // 0 = 0
    printf("Result: %d\n", c);
    return 0;
}
//gcc 4.c -o 4.exe
//.\4.exe