#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int id;
    float salary;
} Employee;

int main(void) {
    int n;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    if (n <= 0) { printf("Invalid number.\n"); return 0; }

    Employee *arr = (Employee *)malloc((size_t)n * sizeof(Employee));
    if (!arr) { printf("Allocation failed.\n"); return 1; }

    for (int i = 0; i < n; i++) {
        printf("\n-- Employee %d --\n", i + 1);
        printf("Enter name: ");
        scanf("%49s", arr[i].name);
        printf("Enter id: ");
        scanf("%d", &arr[i].id);
        printf("Enter salary: ");
        scanf("%f", &arr[i].salary);
    }

    printf("\n== Employee Records ==\n");
    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: %s\n", arr[i].name);
        printf("ID: %d\n", arr[i].id);
        printf("Salary: %.2f\n", arr[i].salary);
    }

    free(arr);
    return 0;
}


//gcc 3.c -o 3.exe && .\3.exe
//./3.exe