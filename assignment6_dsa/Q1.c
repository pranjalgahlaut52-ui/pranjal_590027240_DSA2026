#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* newNode(int val)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct node* insert(struct node* root, int val)
{
    if(root == NULL) return newNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);

    return root;
}

struct node* minValue(struct node* root)
{
    while(root->left) root = root->left;
    return root;
}

struct node* delete(struct node* root, int key)
{
    if(root == NULL) return root;

    if(key < root->data)
        root->left = delete(root->left, key);
    else if(key > root->data)
        root->right = delete(root->right, key);
    else
    {
        if(root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValue(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }

    return root;
}

int search(struct node* root, int key)
{
    if(root == NULL) return 0;
    if(root->data == key) return 1;
    if(key < root->data) return search(root->left, key);
    return search(root->right, key);
}

void inorder(struct node* root)
{
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    struct node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    inorder(root);

    printf("\nSearch 40: %d", search(root, 40));

    root = delete(root, 30);

    printf("\nAfter deletion:\n");
    inorder(root);

    return 0;
}
