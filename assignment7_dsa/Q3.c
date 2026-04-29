#include <stdio.h>

int main() {
    int n, edges;
    int adj[10][10] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    int u, v;

    for(int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    printf("\nAdjacency Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    int vertex;
    printf("\nEnter vertex: ");
    scanf("%d", &vertex);

    int indegree = 0, outdegree = 0;

    for(int i = 0; i < n; i++) {
        if(adj[i][vertex]) indegree++;
        if(adj[vertex][i]) outdegree++;
    }

    printf("In-degree: %d\n", indegree);
    printf("Out-degree: %d\n", outdegree);

    return 0;
}
