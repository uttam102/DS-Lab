// 1. Dynamic Memory Allocation for String Input
// Dynamically allocate memory for a string and take input from the user. Print
// the string length manually.

#include <stdio.h>
#include <stdlib.h>

static int manual_strlen(const char *s) {
    int len = 0;
    if (s == NULL) return 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

int main(void) {
    int capacity = 256; // simple fixed capacity
    char *str = (char *)malloc((size_t)capacity);
    if (str == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter a string: ");
    if (fgets(str, capacity, stdin) == NULL) {
        printf("Input error.\n");
        free(str);
        return 1;
    }

    // remove trailing newline if present
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') { str[i] = '\0'; break; }
    }

    int len = manual_strlen(str);
    printf("You entered: %s\n", str);
    printf("Manual length: %d\n", len);

    free(str);
    return 0;
}


//gcc 1.c -o 1.exe
//./1.exe