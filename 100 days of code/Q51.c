#include <stdio.h>
#include <stdlib.h>

// BST Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA in BST
struct Node* LCA(struct Node* root, int p, int q) {
    if (root == NULL)
        return NULL;

    // If both values are smaller → go left
    if (p < root->data && q < root->data)
        return LCA(root->left, p, q);

    // If both values are greater → go right
    if (p > root->data && q > root->data)
        return LCA(root->right, p, q);

    // This node is the split point → LCA
    return root;
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    struct Node* root = NULL;

    // Build BST
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    struct Node* lca = LCA(root, p, q);

    printf("%d\n", lca->data);

    return 0;
}