/*Extend a Binary Search Tree program to support deletion. The program should create a BST, delete a user-specified node, correctly handle nodes with zero, one and
two children, and display inorder traversal before and after deletion. Test the program separately for all three deletion cases. */ 
#include <stdio.h>
#include <stdlib.h>

// Structure of a BST node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a node into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find the smallest node in a subtree
struct Node* findMin(struct Node* root) {
    struct Node* current = root;

    while (current != NULL && current->left != NULL)
        current = current->left;

    return current;
}

// Delete a node from BST
struct Node* deleteNode(struct Node* root, int value) {

    // Node not found
    if (root == NULL)
        return root;

    // Search in left subtree
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }

    // Search in right subtree
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }

    // Node found
    else {

        // Case 1: No children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Case 2: Only right child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        // Case 2: Only left child
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        else {
            struct Node* temp = findMin(root->right);

            // Copy inorder successor's value
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value, deleteValue;
    int i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nInorder traversal before deletion: ");
    inorder(root);

    printf("\nEnter value to delete: ");
    scanf("%d", &deleteValue);

    root = deleteNode(root, deleteValue);

    printf("\nInorder traversal after deletion: ");
    inorder(root);

    printf("\n");

    return 0;
}
