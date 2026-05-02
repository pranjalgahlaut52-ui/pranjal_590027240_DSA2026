#include <stdio.h>
#include <stdlib.h>

// BST Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert function in BST
struct Node* insert(struct Node* root, int key) {
    // If tree is empty, return new node
    if (root == NULL)
        return newNode(key);

    // Go to left subtree
    if (key < root->data)
        root->left = insert(root->left, key);

    // Go to right subtree
    else if (key > root->data)
        root->right = insert(root->right, key);

    // return unchanged root
    return root;
}

// Inorder traversal (to check BST)
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Main function
int main() {
    struct Node* root = NULL;

    // Insert elements
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder Traversal of BST: ");
    inorder(root);

    return 0;
}