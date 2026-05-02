#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

int stack[MAX];
int top = -1;

// create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// directed edge
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// push into stack
void push(int x) {
    stack[++top] = x;
}

// DFS
void dfs(int node) {
    visited[node] = 1;

    struct Node* temp = adj[node];

    while (temp != NULL) {
        int neigh = temp->vertex;

        if (!visited[neigh]) {
            dfs(neigh);
        }

        temp = temp->next;
    }

    // push after visiting all children
    push(node);
}

int main() {
    int n, m;
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

    // DFS for all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // print stack in reverse order
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}