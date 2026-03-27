#include <stdio.h>
#include <stdlib.h>
struct node
{
 int data;
struct node *next;
}; struct node *top = NULL;

void push(){

    struct node *newnode;
    int x;
       newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter element: ");
    scanf("%d",&x);
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop() {
    struct node *temp;
    if(top == NULL)
        printf("the stack is underflow \n");
    else
    {
        temp = top;
        printf("Deleted element from stack: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}
void display(){
    struct node *temp;
    if(top == NULL)
        printf("Stack is empty\n");
    else
    {
        temp = top;
        printf("Stack elements:\n");
        while(temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    int choice;

    printf("1.Push\n2.Pop\n3.Display\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: push(); break;
        case 2: pop(); break;
        case 3: display(); break;
        default: printf("Invalid choice");
    }

    return 0;
}