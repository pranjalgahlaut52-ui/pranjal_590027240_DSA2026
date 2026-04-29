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

struct node* stack[100];
int top = -1;

void push(struct node* n)
{
    stack[++top] = n;
}

struct node* pop()
{
    return stack[top--];
}

int main()
{
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);

    struct node* curr = root;

    while(curr || top != -1)
    {
        while(curr)
        {
            push(curr);
            curr = curr->left;
        }
        curr = pop();
        printf("%d ", curr->data);
        curr = curr->right;
    }

    printf("\n");

    push(root);
    while(top != -1)
    {
        struct node* n = pop();
        printf("%d ", n->data);

        if(n->right) push(n->right);
        if(n->left) push(n->left);
    }

    return 0;
}
