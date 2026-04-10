#include <stdio.h>

typedef struct {
    char name[50];
    int roll;
    float marks;
} Student;

int main(void) {
    Student s;
    printf("Enter name: ");
    scanf("%49s", s.name);
    printf("Enter roll number: ");
    scanf("%d", &s.roll);
    printf("Enter marks: ");
    scanf("%f", &s.marks);

    printf("\n-- Student Details --\n");
    printf("Name: %s\n", s.name);
    printf("Roll: %d\n", s.roll);
    printf("Marks: %.2f\n", s.marks);
    return 0;
}

//gcc 2.c -o 2.exe
//./2.exe

