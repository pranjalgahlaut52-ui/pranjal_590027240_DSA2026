#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

// Function to create a node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end (for initial list)
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}
struct Node* insertAtPosition(struct Node* head, int value, int pos) {
    struct Node* newNode = createNode(value);
    if (pos == 1) {     // insert the begnning 
        newNode->next = head;  
        return newNode;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Display list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Create initial list
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 12);

    printf("Before insertion: ");
    display(head);
    head = insertAtPosition(head, 30, 3);

    printf("After insertion: ");
    display(head);
    return 0;
}
