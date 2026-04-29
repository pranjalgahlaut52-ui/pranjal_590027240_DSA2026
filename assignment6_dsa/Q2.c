#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* create(int val)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

int count(struct node* root)
{
    if(root == NULL) return 0;
    return 1 + count(root->left) + count(root->right);
}

int leaf(struct node* root)
{
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return leaf(root->left) + leaf(root->right);
}

int height(struct node* root)
{
    if(root == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

int main()
{
    struct node* root = create(1);
    root->left = create(2);
    root->right = create(3);
    root->left->left = create(4);
    root->left->right = create(5);

    printf("Total nodes: %d\n", count(root));
    printf("Leaf nodes: %d\n", leaf(root));
    printf("Height: %d\n", height(root));

    return 0;
}
