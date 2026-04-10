#include <stdio.h>

#define MAX 100

void dfs(int graph[MAX][MAX], int visited[], int startNode, int n) {
    printf("%d ", startNode);
    visited[startNode] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[startNode][i] == 1 && !visited[i]) {
            dfs(graph, visited, i, n);
        }
    }
}

int main() {
    int n, e, u, v, startNode;
    int graph[MAX][MAX] = {0};
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &startNode);

    printf("DFS Traversal Order: ");
    dfs(graph, visited, startNode, n);
    printf("\n");

    return 0;
}