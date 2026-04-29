#include <stdio.h>

int queue[20], front = -1, rear = -1;

void enqueue(int x) {
    if(front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int main() {
    int n, adj[10][10], visited[10] = {0};
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while(front <= rear) {
        int v = dequeue();
        printf("%d ", v);

        for(int i = 0; i < n; i++) {
            if(adj[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}
