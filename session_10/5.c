#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int V, E;
    int i, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    int** adjMatrix = (int**)malloc(V * sizeof(int*));
    for (i = 0; i < V; i++) {
        adjMatrix[i] = (int*)calloc(V, sizeof(int));
    }

    struct Node** adjList = (struct Node**)malloc(V * sizeof(struct Node*));
    for (i = 0; i < V; i++) {
        adjList[i] = NULL;
    }

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (source destination):\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);

        if (u >= V || v >= V || u < 0 || v < 0) {
            i--;
            continue;
        }

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;

        struct Node* newNode = createNode(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;

        newNode = createNode(u);
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }

    printf("\n--- Adjacency Matrix ---\n");
    printf("   ");
    for (i = 0; i < V; i++) printf("%d ", i);
    printf("\n");
    
    for (i = 0; i < V; i++) {
        printf("%d: ", i);
        for (int j = 0; j < V; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\n--- Adjacency List ---\n");
    for (i = 0; i < V; i++) {
        printf("Vertex %d:", i);
        struct Node* temp = adjList[i];
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf(" -> NULL\n");
    }

    for (i = 0; i < V; i++) free(adjMatrix[i]);
    free(adjMatrix);
    
    for (i = 0; i < V; i++) {
        struct Node* temp = adjList[i];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(adjList);

    return 0;
}