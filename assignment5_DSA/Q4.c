#include <stdio.h>
#include <stdlib.h>
// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};// Create node
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
}// Queue using array
#define SIZE 100
struct Node* queue[SIZE];
int front = -1, rear = -1;
// Enqueue
void enqueue(struct Node* node) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
        return;
    }if (front == -1)
        front = 0;
    queue[++rear] = node;
}// Dequeue
struct Node* dequeue() {
    if (front == -1 || front > rear)
        return NULL;
    return queue[front++];
}// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL)
        return;
    enqueue(root);
    while (front <= rear) {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);
        if (temp->left != NULL)
            enqueue(temp->left);
        if (temp->right != NULL)
            enqueue(temp->right);
    }
}int main() {
    struct Node* root = NULL;
   printf("Create Binary Tree:\n");
    root = insert();
    printf("\nLevel Order Traversal: ");
    levelOrder(root);
    return 0;
}