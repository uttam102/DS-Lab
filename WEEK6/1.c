#include <stdio.h>
#define MAX_SIZE 100

void insert(int arr[], int *size) {
    int pos, val;
    if (*size >= MAX_SIZE) {
        printf("Array overflow!\n");
        return;
    }
    printf("Enter position to insert (0-%d): ", *size);
    scanf("%d", &pos);
    if (pos < 0 || pos > *size) {
        printf("Invalid position!\n");
        return;
    }
    printf("Enter value to insert: ");
    scanf("%d", &val);
    for (int i = *size; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = val;
    (*size)++;
    printf("Inserted %d at position %d.\n", val, pos);
}

void delete(int arr[], int *size) {
    int pos;
    if (*size <= 0) {
        printf("Array underflow!\n");
        return;
    }
    printf("Enter position to delete (0-%d): ", *size-1);
    scanf("%d", &pos);
    if (pos < 0 || pos >= *size) {
        printf("Invalid position!\n");
        return;
    }
    int val = arr[pos];
    for (int i = pos; i < *size-1; i++) {
        arr[i] = arr[i+1];
    }
    (*size)--;
    printf("Deleted %d from position %d.\n", val, pos);
}

void traverse(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[MAX_SIZE], size = 0, choice;
    while (1) {
        printf("\nArray Operations Menu:\n");
        printf("1. Insert\n2. Delete\n3. Traverse\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert(arr, &size); break;
            case 2: delete(arr, &size); break;
            case 3: traverse(arr, size); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
