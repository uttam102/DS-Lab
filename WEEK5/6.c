#include <stdio.h>

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    char name[50];
    int id;
    float salary;
    Date doj; // date of joining
} Employee;

int main(void) {
    Employee e;
    printf("Enter name : ");
    scanf("%49s", e.name);
    printf("Enter id: ");
    scanf("%d", &e.id);
    printf("Enter salary: ");
    scanf("%f", &e.salary);
    printf("Enter DOJ (dd mm yyyy): ");
    scanf("%d %d %d", &e.doj.day, &e.doj.month, &e.doj.year);

    printf("\n-- Employee with DOJ --\n");
    printf("Name: %s\n", e.name);
    printf("ID: %d\n", e.id);
    printf("Salary: %.2f\n", e.salary);
    printf("Date of Joining: %02d-%02d-%04d\n", e.doj.day, e.doj.month, e.doj.year);
    return 0;
}


//gcc 6.c -o 6.exe && .\6.exe
//./6.exe