#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Node of adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph adjacency list
struct Node* adj[MAX];

// Visited array
int visited[MAX];

// Queue
int queue[MAX];
int front = 0, rear = 0;

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected graph)
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// Queue operations
void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

// BFS function
void BFS(int start) {
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        struct Node* temp = adj[node];

        while (temp != NULL) {
            int neighbor = temp->vertex;

            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                enqueue(neighbor);
            }

            temp = temp->next;
        }
    }
}

int main() {
    int n, m, s;
    scanf("%d %d", &n, &m);

    // initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    int u, v;

    // input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // source vertex
    scanf("%d", &s);

    BFS(s);

    return 0;
}