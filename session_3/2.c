/*2. Linear Search in Array
Search for an element in an array and return its index using linear search
technique.
*/
#include <stdio.h>
int main() {
    int arr[100], n, key, i, found = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &key);
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Element not found.\n");
    }
    return 0;
}
//gcc .c -o 2.exe
//./2.exe