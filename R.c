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

// Function to perform iterative preorder traversal
void iterativePreorder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack[100];
    int top = -1;

    stack[++top] = root;

    while (top >= 0) {
        struct Node* node = stack[top--];
        printf("%d ", node->data);

        if (node->right)
            stack[++top] = node->right;

        if (node->left)
            stack[++top] = node->left;
    }
}

// Function to perform iterative inorder traversal
void iterativeInorder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Function to perform iterative postorder traversal
void iterativePostorder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack1[100];
    struct Node* stack2[100];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        struct Node* node = stack1[top1--];
        stack2[++top2] = node;

        if (node->left)
            stack1[++top1] = node->left;

        if (node->right)
            stack1[++top1] = node->right;
    }

    while (top2 >= 0) {
        struct Node* node = stack2[top2--];
        printf("%d ", node->data);
    }
}

// Main function to test the program
int main() {
    struct Node* root = NULL;

    // Build the binary tree (you can modify this part based on your input method)
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

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
