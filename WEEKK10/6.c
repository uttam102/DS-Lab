#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    int item = queue[front];
    front++;
    return item;
}

int isEmpty() {
    if (front == -1 || front > rear)
        return 1;
    return 0;
}

void bfs(int graph[MAX][MAX], int visited[], int startNode, int n) {
    enqueue(startNode);
    visited[startNode] = 1;

    printf("BFS Traversal Order: ");

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, e;
    int graph[MAX][MAX] = {0};
    int visited[MAX] = {0};
    int u, v, startNode;

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

    bfs(graph, visited, startNode, n);

    return 0;
}