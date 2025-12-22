#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createTree() {
    int value;
    struct Node* newNode;

    printf("Enter data (-1 for no node): ");
    scanf("%d", &value);

    if (value == -1)
        return NULL;

    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    printf("Enter left child of %d\n", value);
    newNode->left = createTree();

    printf("Enter right child of %d\n", value);
    newNode->right = createTree();

    return newNode;
}

// Function to find height of the tree
int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to count total nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to count nodes with two children
int countTwoChildNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    int count = 0;
    if (root->left != NULL && root->right != NULL)
        count = 1;

    return count + countTwoChildNodes(root->left) + countTwoChildNodes(root->right);
}

int main() {
    struct Node* root;

    printf("Create Binary Tree\n");
    root = createTree();

    printf("\nHeight of tree: %d", height(root));
    printf("\nTotal number of nodes: %d", countNodes(root));
    printf("\nNumber of leaf nodes: %d", countLeafNodes(root));
    printf("\nNumber of nodes with two children: %d", countTwoChildNodes(root));
    printf("\n");

    return 0;
}

