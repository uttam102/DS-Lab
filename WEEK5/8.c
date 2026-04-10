#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int roll;
    float marks;
} Student;

int main(void) {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    if (n <= 0) { printf("Invalid number.\n"); return 0; }

    Student *arr = (Student *)malloc((size_t)n * sizeof(Student));
    if (!arr) { printf("Allocation failed.\n"); return 1; }

    for (int i = 0; i < n; i++) {
        printf("\n-- Student %d --\n", i + 1);
        printf("Enter name (no spaces): ");
        scanf("%49s", arr[i].name);
        printf("Enter roll: ");
        scanf("%d", &arr[i].roll);
        printf("Enter marks: ");
        scanf("%f", &arr[i].marks);
    }

    printf("\n== Student Records ==\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", arr[i].name);
        printf("Roll: %d\n", arr[i].roll);
        printf("Marks: %.2f\n", arr[i].marks);
    }

    free(arr);
    return 0;
}


//gcc 8.c -o 8.exe && .\8.exe
//./8.exe