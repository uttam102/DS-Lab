//5. Pointer Arithmetic Use pointer arithmetic to access and print values from an integer array.

#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr; // A pointer to the first element of the array

    printf("Values of the array using pointer arithmetic:\n");
    
    for (int i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i, *(ptr + i));
    }

    return 0;
}