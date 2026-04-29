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

struct node* q[100];
int f = 0, r = -1;

void enqueue(struct node* n)
{
    q[++r] = n;
}

struct node* dequeue()
{
    return q[f++];
}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    enqueue(root);

    while(f <= r)
    {
        struct node* temp = dequeue();
        printf("%d ", temp->data);

        if(temp->left) enqueue(temp->left);
        if(temp->right) enqueue(temp->right);
    }

    return 0;
}
