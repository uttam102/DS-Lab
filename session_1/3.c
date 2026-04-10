/*3. Area and Perimeter of Shapes
Calculate area and perimeter of a rectangle and a circle using constants and
appropriate operators.*/

#include <stdio.h>

#define PI 3.14

int main() {
    float length, width, area, perimeter, radius, area_circle, perimeter_circle;
    // Rectangle
    printf("Enter length of the rectangle: ");
    scanf("%f", &length);
    printf("Enter width of the rectangle:");
    scanf("%f", &width);
    area = length * width;
    perimeter = 2 * (length + width);
    printf("Area of the rectangle: %.2f\n", area);
    printf("Perimeter of the rectangle: %.2f\n\n", perimeter);
    // Circle
    printf("Enter radius of the circle: ");
    scanf("%f", &radius);
    area_circle = PI * radius * radius;
    printf("Area of the circle: %.2f\n", area_circle);
    perimeter_circle = 2 * PI * radius;
    printf("Perimeter of the circle: %.2f\n", perimeter_circle);
    return 0;
}
//gcc 3.c -o 3.exe
//.\3.exe