#include <stdio.h>
#define SIZE 100
int tree[SIZE];
// Initialize tree 
void init() {
    for (int i = 0; i < SIZE; i++) {
        tree[i] = -1;
    }
}
// Insert element at given index
void insert(int value, int index) {
    if (index >= SIZE) {
        printf("Index out of range\n");
        return;
    }
    tree[index] = value;
}
// Display tree elements
void display() {
    printf("Tree elements:\n");
    for (int i = 0; i < SIZE; i++) {
        if (tree[i] != -1) {
            printf("Index %d : %d\n", i, tree[i]);
        }
    }
}
// Find parent, left child, right child
void relations(int index) {
    if (tree[index] == -1) {
        printf("Node not found\n");
        return;
    } printf("Node value: %d\n", tree[index]);
    // Parent
    if (index == 0) {
        printf("No parent (root node)\n");
    } else {
        printf("Parent: %d\n", tree[(index - 1) / 2]);
    }
    // Left Child
    if (2 * index + 1 < SIZE && tree[2 * index + 1] != -1) {
        printf("Left Child: %d\n", tree[2 * index + 1]);
    } else {
        printf("No Left Child\n");
    }
    // Right Child
    if (2 * index + 2 < SIZE && tree[2 * index + 2] != -1) {
        printf("Right Child: %d\n", tree[2 * index + 2]);
    } else {
        printf("No Right Child\n");
    }
}
int main() {
    int choice, value, index;
    init();
    while (1) {
        printf("\n--- Binary Tree Menu ---\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Find Parent/Children\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter index: ");
                scanf("%d", &index);
                insert(value, index);
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Enter index: ");
                scanf("%d", &index);
                relations(index);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}