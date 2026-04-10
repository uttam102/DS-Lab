#include <stdio.h>

typedef struct {
    char name[50];
    int roll;
    float marks;
} Student;

int main(void) {
    Student s;
    Student *ps = &s;

    printf("Enter name : ");
    scanf("%49s", ps->name);
    printf("Enter roll: ");
    scanf("%d", &ps->roll);
    printf("Enter marks: ");
    scanf("%f", &ps->marks);

    printf("\n-- Access via pointer (->) --\n");
    printf("Name: %s\n", ps->name);
    printf("Roll: %d\n", ps->roll);
    printf("Marks: %.2f\n", ps->marks);
    return 0;
}


//gcc 7.c -o 7.exe && .\7.exe
//./7.exe