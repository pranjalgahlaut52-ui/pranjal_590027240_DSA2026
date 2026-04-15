#include <stdio.h>
#include <stdlib.h>
// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};// Create new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}// Insert nodes (user input)
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
}// Inorder Traversal (LNR)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}// Preorder Traversal (NLR)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}// Postorder Traversal (LRN)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}int main() {
    struct Node* root = NULL;
   printf("Create Binary Tree:\n");
    root = insert();
    printf("\nInorder Traversal: ");
    inorder(root);
    printf("\nPreorder Traversal: ");
    preorder(root);
    printf("\nPostorder Traversal: ");
    postorder(root);
    return 0;
}