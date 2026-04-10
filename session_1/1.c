/*  1. Simple Interest Calculator
    Write a program to calculate simple interest using the formula
    SI = (P × R × T) / 100.*/

#include <stdio.h>
int main() {
    float p, r, SI;
    int t;
    // Asking user to enter principal amount, rate of interest and time period
    printf("Enter the principal amount (P): ");
    scanf("%f", &p);

    printf("Enter the rate of interest (R): ");
    scanf("%f", &r);

    printf("Enter the time period in years (T): ");
    scanf("%d", &t);

    // Calculating simple interest
    SI = (p * r * t) / 100;

    // Displaying the result in two decimal places for use %.2f
    printf("Simple Interest (SI) = %.2f\n", SI);
    return 0;
}


//gcc 1.c -o 1.exe
//./1.exe