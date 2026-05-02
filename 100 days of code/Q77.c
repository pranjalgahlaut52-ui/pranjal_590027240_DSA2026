#include <stdio.h>

#define MAX 1000

int adj[MAX][MAX];
int vis[MAX];
int n;

void dfs(int node) {

    vis[node] = 1;

    for (int i = 1; i <= n; i++) {
        if (adj[node][i] == 1 && !vis[i]) {
            dfs(i);
        }
    }
}

int main() {

    int m;
    scanf("%d %d", &n, &m);

    // initialize adjacency matrix
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        for (int j = 1; j <= n; j++) {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    dfs(1);

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) count++;
    }

    if (count == n)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}