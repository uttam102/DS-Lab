/*1. Sort an Array (Ascending/Descending)
Use for loops to sort a one-dimensional array using selection
algorithm.
*/
#include <stdio.h>

int main() {
    int arr[100], n, i, j, temp;
    int order;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter 1 for Ascending, 2 for Descending: ");
    scanf("%d", &order);
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if ((order == 1 && arr[j] > arr[j + 1]) || 
                (order == 2 && arr[j] < arr[j + 1])) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("\nSorted Array: ");// Display
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

//gcc 1.c -o 1.exe
//./1.exe
