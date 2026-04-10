#include <stdio.h>
int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high) return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == key) return mid;
    else if (arr[mid] < key) return binarySearchRecursive(arr, mid + 1, high, key);
    else return binarySearchRecursive(arr, low, mid - 1, key);
}
int main() {
    int n, key, i, res;
    int arr[100];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    scanf("%d", &key);
    res = binarySearchIterative(arr, n, key);
    printf(res == -1 ? "Not Found\n" : "Found at %d\n", res);
    res = binarySearchRecursive(arr, 0, n - 1, key);
    printf(res == -1 ? "Not Found\n" : "Found at %d\n", res);
}