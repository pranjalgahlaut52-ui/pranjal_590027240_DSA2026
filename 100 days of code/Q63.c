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

// DFS function
void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];

    while (temp != NULL) {
        int neighbor = temp->vertex;

        if (!visited[neighbor]) {
            DFS(neighbor);
        }

        temp = temp->next;
    }
}

int main() {
    int n, m, s;
    scanf("%d %d", &n, &m);

    // initialize graph
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

    // starting vertex
    scanf("%d", &s);

    DFS(s);

    return 0;
}