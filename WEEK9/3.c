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

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct Node *root = NULL;
    root = create();
    printf("Preorder: "); preorder(root);
    printf("\nInorder: "); inorder(root);
    printf("\nPostorder: "); postorder(root);
    return 0;
}
