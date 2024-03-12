#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the binary tree
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);

    return root;
}

// Function to perform iterative preorder traversal
void iterativePreorder(struct Node* root) {
    // (same as before)
}

// Function to perform iterative inorder traversal
void iterativeInorder(struct Node* root) {
    // (same as before)
}

// Function to perform iterative postorder traversal
void iterativePostorder(struct Node* root) {
    // (same as before)
}

// Main function to test the program
int main() {
    struct Node* root = NULL;
    int n, value;

    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &n);

    printf("Enter the values of the nodes:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("Preorder Traversal: ");
    iterativePreorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    iterativeInorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    iterativePostorder(root);
    printf("\n");

    return 0;
}
