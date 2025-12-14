#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


struct Node* insert (struct Node* root, int val){
    if(root == NULL){
        return createNode(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }else if(val > root->data){
        root->right = insert(root->right, val);
    }
    return root;
}

void inOrderTraversal(struct Node* root){
    if(root != NULL){
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(struct Node* root){
    if(root != NULL){
        printf("%d ", root->data);
        inOrderTraversal(root->left);
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(struct Node* root){
    if(root != NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    struct Node* root = NULL;
    int num, count, i;
    int value;

    printf("--- Binary Search Tree Builder ---\n");
    printf("Enter the number of elements you want to insert: ");
    if (scanf("%d", &count) != 1 || count <= 0) {
        printf("Invalid input for count.\n");
        return 1;
    }
    
    printf("Enter %d integer elements one by one:\n", count);
    for (i = 0; i < count; i++) {
        printf("Element %d: ", i + 1);
        if (scanf("%d", &value) != 1) {
            printf("Invalid input. Stopping input.\n");
            break;
        }
        root = insert(root, value);
    }

    // Show the results of the traversals on the user-built tree
    printf("\n--- Traversal Results (for the BST) ---\n");
    
    printf("1. In-order Traversal (Left -> Root -> Right):\n");
    printf("   (Always prints keys in sorted order for a BST)\n");
    inOrderTraversal(root);
    printf("\n\n");

    printf("2. Pre-order Traversal (Root -> Left -> Right):\n");
    preOrderTraversal(root);
    printf("\n\n");
    
    printf("3. Post-order Traversal (Left -> Right -> Root):\n");
    postOrderTraversal(root);
    printf("\n");

    return 0;
}