#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int hasCycleUndirected(int graph[MAX][MAX], int v, int visited[], int parent, int n) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i]) {
            if (!visited[i]) {
                if (hasCycleUndirected(graph, i, visited, v, n))
                    return 1;
            } 
            else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int hasCycleDirected(int graph[MAX][MAX], int v, int visited[], int recStack[], int n) {
    if (!visited[v]) {
        visited[v] = 1;
        recStack[v] = 1;

        for (int i = 0; i < n; i++) {
            if (graph[v][i]) {
                if (!visited[i] && hasCycleDirected(graph, i, visited, recStack, n))
                    return 1;
                else if (recStack[i])
                    return 1;
            }
        }
    }
    recStack[v] = 0;
    return 0;
}

int main() {
    int n, e, u, v, choice;
    int graph[MAX][MAX] = {0};
    int visited[MAX] = {0};
    int recStack[MAX] = {0};
    int cycleFound = 0;

    printf("1. Undirected Graph\n2. Directed Graph\nEnter choice: ");
    scanf("%d", &choice);

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        if (choice == 1) {
            graph[v][u] = 1;
        }
    }

    if (choice == 1) {
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (hasCycleUndirected(graph, i, visited, -1, n)) {
                    cycleFound = 1;
                    break;
                }
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (hasCycleDirected(graph, i, visited, recStack, n)) {
                    cycleFound = 1;
                    break;
                }
            }
        }
    }

    if (cycleFound)
        printf("Cycle Detected\n");
    else
        printf("No Cycle Detected\n");

    return 0;
}