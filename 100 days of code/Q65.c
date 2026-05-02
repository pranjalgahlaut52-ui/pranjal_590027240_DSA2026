#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int visited[MAX];

// create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// add undirected edge
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS with parent tracking
bool dfs(int node, int parent) {
    visited[node] = 1;

    struct Node* temp = adj[node];

    while (temp != NULL) {
        int neigh = temp->vertex;

        // not visited → go deeper
        if (!visited[neigh]) {
            if (dfs(neigh, node))
                return true;
        }
        // visited & not parent → cycle found
        else if (neigh != parent) {
            return true;
        }

        temp = temp->next;
    }

    return false;
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

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    // check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}