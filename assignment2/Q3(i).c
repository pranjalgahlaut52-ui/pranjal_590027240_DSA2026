#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
// function to start at the beginning of the linked list 
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    return newNode;   }
    // to display 
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } printf("the value is zero or NULL\n");
}

int main() {
    struct Node* head = NULL;
    head = insertAtBeginning(head, 124);
    head = insertAtBeginning(head, 12);
    head = insertAtBeginning(head, 4);
    display(head);
    return 0;
}
