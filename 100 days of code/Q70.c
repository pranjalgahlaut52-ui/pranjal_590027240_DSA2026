#include <stdio.h>
#include <limits.h>

#define MAX 1000

struct Edge {
    int u, v, w;
};

int main() {

    int n, m, src;
    scanf("%d %d", &n, &m);

    struct Edge edges[MAX];

    // input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    scanf("%d", &src);

    int dist[MAX];

    // initialize distances
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    // Step 1: Relax all edges (n-1 times)
    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < m; j++) {

            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if (dist[u] != INT_MAX &&
                dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 2: Check negative cycle
    for (int j = 0; j < m; j++) {

        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if (dist[u] != INT_MAX &&
            dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    // print shortest distances
    for (int i = 0; i < n; i++) {
        printf("Node %d Distance = %d\n", i, dist[i]);
    }

    return 0;
}