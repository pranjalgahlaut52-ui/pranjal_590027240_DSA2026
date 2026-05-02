#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue node for BFS
struct QNode {
    struct Node* node;
    int hd; // horizontal distance
};

// Queue
struct QNode queue[MAX];
int front = 0, rear = 0;

void enqueue(struct Node* node, int hd) {
    queue[rear].node = node;
    queue[rear].hd = hd;
    rear++;
}

struct QNode dequeue() {
    return queue[front++];
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

// Vertical order traversal
void verticalOrder(struct Node* root) {
    if (root == NULL)
        return;

    // To store nodes by horizontal distance
    int map[2000][100]; // [hd][values]
    int count[2000] = {0};

    int offset = 1000; // to handle negative HD

    front = rear = 0;
    enqueue(root, 0);

    while (front < rear) {
        struct QNode temp = dequeue();

        struct Node* curr = temp.node;
        int hd = temp.hd;

        map[hd + offset][count[hd + offset]++] = curr->data;

        if (curr->left)
            enqueue(curr->left, hd - 1);

        if (curr->right)
            enqueue(curr->right, hd + 1);
    }

    // Print from leftmost to rightmost
    for (int i = 0; i < 2000; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
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

    verticalOrder(root);

    return 0;
}