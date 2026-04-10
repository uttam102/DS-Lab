/*3. String Length without strlen()
Input a string and calculate its length manually (without using string library
functions)*/

#include <stdio.h>
int main() {
    char str[100];
    int i = 0, length = 0;
    printf("Enter a string: ");
    // Read entire line including spaces until newline
    scanf("%s", str);
    while(str[i] != '\0') {
        length++;
        i++;
    }
    printf("Length of string = %d\n", length);
    return 0;
}

