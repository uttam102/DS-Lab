//4. Pointer to Integer
//Demonstrate how a pointer stores the address of an integer and accesses its value.

#include <stdio.h>

int main() {
    int number = 25;
    int *ptr_to_number;

    ptr_to_number = &number; 

    printf("Value of 'number': %d\n", number);

    printf("Address of 'number': %p\n", &number);

    printf("Value of 'ptr_to_number' (address it holds): %p\n", ptr_to_number);

    printf("Value accessed through pointer '*ptr_to_number': %d\n", *ptr_to_number);

    return 0;
}