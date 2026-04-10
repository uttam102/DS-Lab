#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

struct Node* buildTree(int in[], int pre[], int inStart, int inEnd, int* preIndex) {
    if (inStart > inEnd)
        return NULL;
    struct Node* node = createNode(pre[*preIndex]);
    (*preIndex)++;
    if (inStart == inEnd)
        return node;
    int inIndex = search(in, inStart, inEnd, node->data);
    node->left = buildTree(in, pre, inStart, inIndex - 1, preIndex);
    node->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);    
   return node;
}
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int inorder[n], preorder[n];
    printf("Enter Inorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }
    printf("Enter Preorder traversal: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }
    int preIndex = 0;
    struct Node* root = buildTree(inorder, preorder, 0, n - 1, &preIndex);
    printf("\nPostorder traversal: ");
    postorder(root);
    printf("\n");   
    return 0;
}