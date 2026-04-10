#include <stdio.h>

typedef struct {
    char name[50];
    int id;
    float salary;
} Employee;

void update_salary(Employee *e, float increment) {
    if (!e) return;
    e->salary += increment;
}

int main(void) {
    Employee e;
    printf("Enter name : ");
    scanf("%49s", e.name);
    printf("Enter id: ");
    scanf("%d", &e.id);
    printf("Enter salary: ");
    scanf("%f", &e.salary);

    float inc;
    printf("Enter increment: ");
    scanf("%f", &inc);

    update_salary(&e, inc);

    printf("\n-- Updated Employee --\n");
    printf("Name: %s\n", e.name);
    printf("ID: %d\n", e.id);
    printf("Salary: %.2f\n", e.salary);
    return 0;
}


//gcc 5.c -o 5.exe && .\5.exe
//./5.exe