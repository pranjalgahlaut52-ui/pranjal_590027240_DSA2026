#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Delete last node
struct Node* deleteEnd(struct Node* head) {
    if (!head) return NULL;              // Empty list
    if (!head->next) {                   // Only one node
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    while (temp->next->next)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    return head;
}

void display(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = malloc(sizeof(struct Node));
    head->data = 10;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 20;
    head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 30;
    head->next->next->next = NULL;

    printf("Before deletion:\n");
    display(head);

    head = deleteEnd(head);

    printf("After deletion:\n");
    display(head);

    return 0;
}