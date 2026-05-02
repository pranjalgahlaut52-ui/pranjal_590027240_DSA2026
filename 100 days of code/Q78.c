#include <stdio.h>

#define INF 100000000

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    int cost[n + 1][n + 1];

    // initialize adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cost[i][j] = INF;
        }
    }

    // read edges
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        cost[u][v] = w;
        cost[v][u] = w;
    }

    int visited[n + 1];
    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    visited[1] = 1;   // start from node 1

    int edges = 0;
    int mstWeight = 0;

    while (edges < n - 1) {

        int min = INF;
        int x = -1, y = -1;

        for (int i = 1; i <= n; i++) {

            if (visited[i]) {

                for (int j = 1; j <= n; j++) {

                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        visited[y] = 1;
        mstWeight += min;
        edges++;
    }

    printf("%d\n", mstWeight);

    return 0;
}s