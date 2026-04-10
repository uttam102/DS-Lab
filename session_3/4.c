/*4. Palindrome String Checker
Check whether a string is a palindrome using array indexing and loop
structures.
*/
#include <stdio.h>
int main() {
    char str[100];
    int i, len = 0, flag = 1;
    printf("Enter a string: ");
    // Read entire line including spaces until newline
    scanf("%s", str);

    while(str[len] != '\0') {
        len++;
    }
    for(i = 0; i < len/2; i++) {
        if(str[i] != str[len-1-i]) {
            flag = 0;
            break;
        }
    }
    if(flag) {
        printf("Palindrome String\n");
    } else {
        printf("Not a Palindrome\n");
    }
    return 0;
}
