#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

// Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
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

// Check completeness using index method
bool isComplete(struct Node* root, int index, int n) {
    if (root == NULL)
        return true;

    if (index >= n)
        return false;

    return isComplete(root->left, 2 * index + 1, n) &&
           isComplete(root->right, 2 * index + 2, n);
}

// Check Min Heap property
bool checkMinHeap(struct Node* root) {
    if (root == NULL)
        return true;

    // leaf node
    if (root->left == NULL && root->right == NULL)
        return true;

    // only left child
    if (root->right == NULL)
        return (root->data <= root->left->data);

    // both children exist
    if (root->data <= root->left->data &&
        root->data <= root->right->data)
        return checkMinHeap(root->left) && checkMinHeap(root->right);

    return false;
}

// Count nodes
int countNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    int totalNodes = countNodes(root);

    if (isComplete(root, 0, totalNodes) && checkMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}