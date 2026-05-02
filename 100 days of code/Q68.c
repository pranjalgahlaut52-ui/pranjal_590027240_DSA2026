#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adj[MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = 0;

// create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// add directed edge
void addEdge(int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// queue operations
void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    int u, v;

    // input edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        addEdge(u, v);
        indegree[v]++;   // increase indegree of v
    }

    // push nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Order: ");

    int count = 0;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        struct Node* temp = adj[node];

        while (temp != NULL) {
            int neigh = temp->vertex;

            indegree[neigh]--;

            if (indegree[neigh] == 0) {
                enqueue(neigh);
            }

            temp = temp->next;
        }
    }

    // cycle check
    if (count != n) {
        printf("\nCycle detected: Topological sort not possible");
    }

    return 0;
}