#include <stdio.h>
#include <stdlib.h>

// BST Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// BST Search function
int searchBST(struct Node* root, int key) {
    // Base case: not found
    if (root == NULL)
        return 0;

    // Found
    if (root->data == key)
        return 1;

    // Go left
    if (key < root->data)
        return searchBST(root->left, key);

    // Go right
    return searchBST(root->right, key);
}

// Main function
int main() {
    struct Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    int key = 3;

    if (searchBST(root, key))
        printf("Key Found\n");
    else
        printf("Key Not Found\n");

    return 0;
}