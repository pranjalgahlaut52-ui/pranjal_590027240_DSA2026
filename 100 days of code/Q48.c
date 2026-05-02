#include <stdio.h>
#include <stdlib.h>

// Tree Node structure
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

// Function to count leaf nodes
int countLeaves(struct Node* root) {
    // empty tree
    if (root == NULL)
        return 0;

    // leaf node condition
    if (root->left == NULL && root->right == NULL)
        return 1;

    // recursive count
    return countLeaves(root->left) + countLeaves(root->right);
}

// Main function
int main() {
    struct Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Number of leaf nodes = %d\n", countLeaves(root));

    return 0;
}