#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
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

// Function to insert a node in BST
struct Node* insert(struct Node* root, int data) {
    // If tree is empty, create a new node
    if (root == NULL) {
        return createNode(data);
    }
    
    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    // If data is equal, do nothing (BST doesn't allow duplicates)
    
    return root;
}

// Function to search for a node in BST
struct Node* search(struct Node* root, int data) {
    // Base cases: root is NULL or data is found
    if (root == NULL || root->data == data) {
        return root;
    }
    
    // If data is smaller, search in left subtree
    if (data < root->data) {
        return search(root->left, data);
    }
    
    // If data is larger, search in right subtree
    return search(root->right, data);
}

// Function to find the minimum value node (used in deletion)
struct Node* findMin(struct Node* root) {
    while (root != NULL && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to delete a node from BST
struct Node* deleteNode(struct Node* root, int data) {
    // Base case: tree is empty
    if (root == NULL) {
        return root;
    }
    
    // If data is smaller, delete from left subtree
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    // If data is larger, delete from right subtree
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    // If data is same as root's data, this is the node to delete
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        
        // Node with two children: get the inorder successor (smallest in right subtree)
        struct Node* temp = findMin(root->right);
        
        // Copy the inorder successor's data to this node
        root->data = temp->data;
        
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}

// Function for inorder traversal (left, root, right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Function to display menu
void displayMenu() {
    printf("\n=== Binary Search Tree Operations ===\n");
    printf("1. Insert a node\n");
    printf("2. Delete a node\n");
    printf("3. Search for a node\n");
    printf("4. Inorder traversal (sorted order)\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, data;
    struct Node* result;
    
    printf("Binary Search Tree Implementation\n");
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Node with value %d inserted successfully.\n", data);
                break;
                
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &data);
                if (search(root, data) != NULL) {
                    root = deleteNode(root, data);
                    printf("Node with value %d deleted successfully.\n", data);
                } else {
                    printf("Node with value %d not found in the tree.\n", data);
                }
                break;
                
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &data);
                result = search(root, data);
                if (result != NULL) {
                    printf("Node with value %d found in the tree.\n", data);
                } else {
                    printf("Node with value %d not found in the tree.\n", data);
                }
                break;
                
            case 4:
                if (root == NULL) {
                    printf("Tree is empty.\n");
                } else {
                    printf("Inorder traversal (sorted order): ");
                    inorderTraversal(root);
                    printf("\n");
                }
                break;
                
            case 5:
                printf("Exiting program...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

