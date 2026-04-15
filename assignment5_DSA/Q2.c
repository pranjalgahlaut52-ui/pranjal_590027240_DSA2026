#include <stdio.h>
#include <stdlib.h>
// Structure of a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}// Insert nodes using user input (recursive)
struct Node* insert() {
    int value;
    printf("Enter value (-1 for no node): ");
    scanf("%d", &value);
   if (value == -1)
        return NULL;
    struct Node* root = createNode(value);
    printf("Enter left child of %d\n", value);
    root->left = insert();
    printf("Enter right child of %d\n", value);
    root->right = insert();
    return root;
}// Count total nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}// Count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}// Find height of tree
int height(struct Node* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}int main() {
    struct Node* root = NULL;
    printf("Create Binary Tree:\n");
    root = insert();
    printf("\nTotal Nodes = %d\n", countNodes(root));
    printf("Leaf Nodes = %d\n", countLeafNodes(root));
    printf("Height of Tree = %d\n", height(root));
     return 0;
}