/*5. Swapping Two Numbers Using Bitwise Operator
Swap two numbers without using a temporary variable, using XOR bitwise
operator.*/

#include <stdio.h>

int main() {
    int a = 20, b = 17;
    printf("Before swapping: a = %d, b = %d\n", a, b);
    // Swapping using XOR bitwise operator
    a = a ^ b; // a now holds the XOR of a and b
    b = a ^ b; // b is now original a
    a = a ^ b; // a is now original b
    

    printf("After swapping: a = %d, b = %d\n", a, b);
    return 0;
}
//gcc 5.c -o 5.exe
//.\5.exe
