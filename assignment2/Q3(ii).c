#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) { // if the taken list is empty 
        return newNode;
    }
    struct Node* temp = head;  // traverse to last node 
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode; // to insert the node at the end 
    return head;
} void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    head = insertAtEnd(head, 4); // insert the elements 
    head = insertAtEnd(head, 12);
    head = insertAtEnd(head, 124);
    head = insertAtEnd(head, 1244);

    printf("Linked List: ");
    display(head);

    return 0;
}



