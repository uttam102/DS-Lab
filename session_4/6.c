//6. Double Pointer Demonstration Use a double pointer to access and modify the value of a variable.

#include <stdio.h>

int main() {
    int value = 100;
    int *ptr1;   // Single pointer to an integer
    int **ptr2;  // Double pointer to an integer

    ptr1 = &value; // ptr1 stores the address of 'value'
    ptr2 = &ptr1;  // ptr2 stores the address of 'ptr1'

    printf("Original value: %d\n", value);

    // Access the value of 'value' using the double pointer
    printf("Value accessed via double pointer '**ptr2': %d\n", **ptr2);

    // Modify the value of 'value' using the double pointer
    **ptr2 = 200;
    
    printf("New value after modification: %d\n", value);

    return 0;
}