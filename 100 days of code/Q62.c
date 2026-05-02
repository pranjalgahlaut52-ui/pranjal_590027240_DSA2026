#include <stdio.h>
#include <stdlib.h>

// Node of adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Array of pointers (graph)
struct Node* adjList[100];

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected graph)
void addEdge(int u, int v) {
    // add v to u's list
    struct Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    // add u to v's list (for undirected graph)
    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

// Print adjacency list
void printGraph(int n) {
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i);

        struct Node* temp = adjList[i];

        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize adjacency list
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
    }

    int u, v;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    printGraph(n);

    return 0;
}