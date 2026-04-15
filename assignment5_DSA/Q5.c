#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* stack[SIZE];
int top = -1;
// Push
void push(struct Node* node) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = node;
}// Pop
struct Node* pop() {
    if (top == -1)
        return NULL;
    return stack[top--];
}// Check empty
int isEmpty() {
    return top == -1;
}// Create node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}// Insert using user input
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
}// Non-recursive Inorder
void inorder(struct Node* root) {
    struct Node* current = root;
       while (current != NULL || !isEmpty()) {
        while (current != NULL) {
            push(current);
            current = current->left;
        }    current = pop();
        printf("%d ", current->data);
        current = current->right;
    }
}// Non-recursive Preorder
void preorder(struct Node* root) {
    if (root == NULL)
        return;
      push(root);
        while (!isEmpty()) {
        struct Node* temp = pop();
        printf("%d ", temp->data);
// Push right first so left is processed first
        if (temp->right != NULL)
            push(temp->right);
        if (temp->left != NULL)
            push(temp->left);
    }
}int main() {
    struct Node* root = NULL;
   printf("Create Binary Tree:\n");
    root = insert();
    printf("\nInorder Traversal (Non-Recursive): ");
    inorder(root);
    printf("\nPreorder Traversal (Non-Recursive): ");
    preorder(root);
    return 0;
}