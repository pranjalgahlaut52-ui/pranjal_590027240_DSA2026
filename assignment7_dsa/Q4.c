#include <stdio.h>

int main() {
    int n;
    int adj[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int flag = 1;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(adj[i][j] != adj[j][i]) {
                flag = 0;
                break;
            }
        }
    }

    if(flag)
        printf("Graph is Undirected\n");
    else
        printf("Graph is Directed\n");

    return 0;
}
