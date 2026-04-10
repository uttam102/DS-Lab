/*7. Grade Calculator Using Ladder if...else
Input a mark and classify the grade (A, B, C, D, F) using ladder if...else.*/

#include <stdio.h>

int main() {
    int mark;
    printf("Enter a mark: ");
    scanf("%d", &mark);

    if (mark >= 90) {
        printf("Grade: A\n");
    } else if (mark >= 80) {
        printf("Grade: B\n");
    } else if (mark >= 70) {
        printf("Grade: C\n");
    } else if (mark >= 60) {
        printf("Grade: D\n");
    } else {
        printf("Grade: F\n");
    }

    return 0;
}
//gcc 7.c -o 7.exe
//.\7.exe