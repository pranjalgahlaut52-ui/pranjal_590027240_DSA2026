#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue for BFS
struct Node* queue[MAX];
int front = -1, rear = -1;

// Queue operations
void enqueue(struct Node* node) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = node;
}

struct Node* dequeue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

// Create new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (!isEmpty()) {
        int levelSize = rear - front + 1;

        for (int i = 0; i < levelSize; i++) {
            struct Node* temp = dequeue();
            printf("%d ", temp->data);

            if (temp->left)
                enqueue(temp->left);

            if (temp->right)
                enqueue(temp->right);
        }

        printf("\n"); // next level
    }
}

// Main function
int main() {
    struct Node* root = newNode(3);
    root->left = newNode(9);
    root->right = newNode(20);
    root->right->left = newNode(15);
    root->right->right = newNode(7);

    printf("Level Order Traversal:\n");
    levelOrder(root);

    return 0;
}