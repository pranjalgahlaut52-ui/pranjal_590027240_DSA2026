#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

// Check if full
int isFull() {
    return (front == (rear + 1) % MAX);
}

// Check if empty
int isEmpty() {
    return (front == -1);
}

// Enqueue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1) { // first element
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
}

// Dequeue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    }

    if (front == rear) {
        front = rear = -1; // queue becomes empty
    } else {
        front = (front + 1) % MAX;
    }
}

// Display queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m, value;

    // Input enqueue count
    scanf("%d", &n);

    // Enqueue elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(value);
    }

    // Input dequeue count
    scanf("%d", &m);

    // Perform dequeue
    for (int i = 0; i < m; i++) {
        dequeue();
    }

    // Display result
    display();

    return 0;
}