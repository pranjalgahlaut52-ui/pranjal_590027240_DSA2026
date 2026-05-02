#include <stdio.h>
#include <limits.h>

#define MAX 100

int adj[MAX][MAX];
int dist[MAX];
int visited[MAX];

int n;

// find node with minimum distance
int minDistance() {
    int min = INT_MAX, index = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }

    return index;
}

void dijkstra(int src) {

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {

        int u = minDistance();
        visited[u] = 1;

        for (int v = 0; v < n; v++) {

            // edge exists and not visited
            if (!visited[v] &&
                adj[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + adj[u][v] < dist[v]) {

                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
}

int main() {

    int m, u, v, w, src;

    scanf("%d %d", &n, &m);

    // initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // input edges (u, v, weight)
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // remove this line for directed graph
    }

    scanf("%d", &src);

    dijkstra(src);

    // output shortest distances
    for (int i = 0; i < n; i++) {
        printf("Node %d Distance = %d\n", i, dist[i]);
    }

    return 0;
}s