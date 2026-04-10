#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void buildTreeRecursive(struct Node* node, char* side);

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

struct Node* mirrorTree(struct Node* root) {
    if (root == NULL) {
        return root;
    }
    
    struct Node* left = mirrorTree(root->left);
    struct Node* right = mirrorTree(root->right);
    
    root->left = right;
    root->right = left;
    
    return root;
}

struct Node* buildSampleTree() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    
    return root;
}

struct Node* buildTreeFromInput() {
    int data;
    struct Node* root = NULL;
    int choice;
    
    printf("\nBuilding binary tree...\n");
    printf("Enter root node value: ");
    scanf("%d", &data);
    root = createNode(data);
    
    printf("\nDo you want to add left child of %d? (1 for Yes, 0 for No): ", data);
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter left child value: ");
        scanf("%d", &data);
        root->left = createNode(data);
        buildTreeRecursive(root->left, "left");
    }
    
    printf("\nDo you want to add right child of %d? (1 for Yes, 0 for No): ", root->data);
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter right child value: ");
        scanf("%d", &data);
        root->right = createNode(data);
        buildTreeRecursive(root->right, "right");
    }
    
    return root;
}

void buildTreeRecursive(struct Node* node, char* side) {
    int data, choice;
    
    printf("\nDo you want to add left child of %d? (1 for Yes, 0 for No): ", node->data);
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter left child value: ");
        scanf("%d", &data);
        node->left = createNode(data);
        buildTreeRecursive(node->left, "left");
    }
    
    printf("\nDo you want to add right child of %d? (1 for Yes, 0 for No): ", node->data);
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter right child value: ");
        scanf("%d", &data);
        node->right = createNode(data);
        buildTreeRecursive(node->right, "right");
    }
}

int main() {
    struct Node* root = NULL;
    int choice;
    
    printf("=== Binary Tree Mirror Operation ===\n\n");
    printf("Choose an option:\n");
    printf("1. Use sample tree\n");
    printf("2. Build tree from input\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        root = buildSampleTree();
        printf("\nSample tree created successfully!\n");
    } else if (choice == 2) {
        root = buildTreeFromInput();
        printf("\nTree created successfully!\n");
    } else {
        printf("Invalid choice! Using sample tree.\n");
        root = buildSampleTree();
    }
    printf("\n=== Before Mirroring ===\n");
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    root = mirrorTree(root);
    printf("\n=== After Mirroring ===\n");
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
    printf("\nTree has been successfully mirrored!\n");   
    return 0;
}