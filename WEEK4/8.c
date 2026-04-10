//8. Dynamic Memory Allocation using malloc() Allocate memory for an array of integers at runtime and perform operations (like finding average).

#include <stdio.h>
#include <stdlib.h> // Required for malloc() and free()

int main() {
    int n, i;
    int *arr;
    float sum = 0.0, average;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory for an array of n integers
    arr = (int *)malloc(n * sizeof(int));

    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // Calculate the average
    average = sum / n;
    printf("The average of the numbers is: %.2f\n", average);

    // Deallocate the memory to prevent memory leaks
    free(arr);

    return 0;
}