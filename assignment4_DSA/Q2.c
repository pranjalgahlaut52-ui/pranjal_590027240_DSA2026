#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;
void enqueue(int val) {
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
   if (rear == NULL) {
        front = rear = temp;
        return;
      }   rear->next = temp;
    rear = temp;
}void dequeue() {
    struct Node* temp;
   if (front == NULL) {
        printf("Queue Empty\n");
        return;
    }
    temp = front;
    printf("Deleted: %d\n", temp->data);
    front = front->next;
    free(temp);
}void display() {
    struct Node* temp;
    temp = front;
   while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void peek() {
    if (front == NULL) {
        printf("Queue Empty\n");
        return;
    }
    printf("Front: %d\n", front->data);
}int main() {
    enqueue(5);
    enqueue(15);
    enqueue(25);
    display();
    peek();
    dequeue();
    display();

    return 0;
}
