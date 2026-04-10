#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* create() {
    int x;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &x);
    if (x == -1) return NULL;
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    printf("Enter left child of %d\n", x);
    newNode->left = create();
    printf("Enter right child of %d\n", x);
    newNode->right = create();
    return newNode;
}

int count(struct Node *root) {
    if (root == NULL) return 0;
    return 1 + count(root->left) + count(root->right);
}

int height(struct Node *root) {
    if (root == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

int main() {
    struct Node *root = NULL;
    root = create();
    printf("Total nodes = %d\n", count(root));
    printf("Height of tree = %d\n", height(root));
    return 0;
}
