/*  2. Temperature Converter
    Convert temperature from Celsius to Fahrenheit and vice versa using appropriate formulas.*/

#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    // Convert Celsius to Fahrenheit
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("%.2f Celsius = %.2f Fahrenheit\n\n", celsius, fahrenheit);

    // Convert Fahrenheit to Celsius
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) * 5 / 9;
    printf("%.2f Fahrenheit = %.2f Celsius\n\n", fahrenheit, celsius);

    return 0;

}
//gcc 2.c -o 2.exe
//./2.exe