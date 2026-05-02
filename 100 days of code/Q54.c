#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue
struct Node* queue[MAX];
int front = 0, rear = 0;

void enqueue(struct Node* node) {
    queue[rear++] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// Create new node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Build tree from level order (-1 = NULL)
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = newNode(arr[i]);
        else
            nodes[i] = NULL;
    }

    int j = 1;
    for (int i = 0; i < n && j < n; i++) {
        if (nodes[i] != NULL) {
            if (j < n)
                nodes[i]->left = nodes[j++];
            if (j < n)
                nodes[i]->right = nodes[j++];
        }
    }

    return nodes[0];
}

// Zigzag traversal
void zigzag(struct Node* root) {
    if (root == NULL)
        return;

    enqueue(root);

    int leftToRight = 1;

    while (!isEmpty()) {
        int size = rear - front;
        int arr[size];

        // store current level
        for (int i = 0; i < size; i++) {
            struct Node* node = dequeue();
            arr[i] = node->data;

            if (node->left)
                enqueue(node->left);
            if (node->right)
                enqueue(node->right);
        }

        // print in required order
        if (leftToRight) {
            for (int i = 0; i < size; i++)
                printf("%d ", arr[i]);
        } else {
            for (int i = size - 1; i >= 0; i--)
                printf("%d ", arr[i]);
        }

        leftToRight = !leftToRight;
    }
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    zigzag(root);

    return 0;
}