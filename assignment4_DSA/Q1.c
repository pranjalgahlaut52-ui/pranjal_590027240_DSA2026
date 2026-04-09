#include <stdio.h>
#define MAX 5
int queue[MAX];
int front = -1, rear = -1;
void enqueue(int val) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;

    rear = rear + 1;
    queue[rear] = val;
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted: %d\n", queue[front]);
    front = front + 1;
}
void display() {
    int i;

    if (front == -1 || front > rear) {
        printf("Queue Empty\n");
        return;
    }

    for (i = front; i <= rear; i++)
        printf("%d ", queue[i]);

    printf("\n");
}
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue Empty\n");
        return;
    }

    printf("Front: %d\n", queue[front]);
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    peek();
    dequeue();
    display();

    return 0;
}

