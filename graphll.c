#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct graph {
    int vertices;
    node **adjList;
} graph;

node *createNode(int data) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

graph *createGraph(int vertices) {
    graph *newGraph = (graph *) malloc(sizeof(graph));
    newGraph->vertices = vertices;
    newGraph->adjList = (node **) malloc(vertices * sizeof(node *));
    for (int i = 0; i < vertices; i++) {
        newGraph->adjList[i] = NULL;
    }
    return newGraph;
}

void addEdge(graph *g, int src, int dest) {
    node *newNode = createNode(dest);
    newNode->next = g->adjList[src];
    g->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = g->adjList[dest];
    g->adjList[dest] = newNode;
}

void printGraph(graph *g) {
    for (int i = 0; i < g->vertices; i++) {
        node *temp = g->adjList[i];
        printf("Vertex %d is connected to: ", i);
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

void BFS(graph *g, int start) {
    int *visited = (int *) calloc(g->vertices, sizeof(int));
    int *queue = (int *) malloc(g->vertices * sizeof(int));
    int front = -1, rear = -1;
    visited[start] = 1;
    queue[++rear] = start;
    while (front != rear) {
        int current = queue[++front];
        printf("%d ", current);
        node *temp = g->adjList[current];
        while (temp) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }
}
void DFS(graph *g, int start) {
    int *visited = (int *) calloc(g->vertices, sizeof(int));
    int *stack = (int *) malloc(g->vertices * sizeof(int));
    int top = -1;
    visited[start] = 1;
    stack[++top] = start;
    while (top != -1) {
        int current = stack[top--];
        printf("%d ", current);
        node *temp = g->adjList[current];
        while (temp) {
            int adjVertex = temp->data;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                stack[++top] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    int vertices; scanf("%d", &vertices);
    graph *g = createGraph(vertices);

    printf("Enter number of edges: ");
    int edges; scanf("%d", &edges);
    for (int i = 0; i < edges; i++) {
        printf("Enter src and dest of edge %d : ", i + 1);
        int src, dest; scanf("%d %d", &src, &dest);
        addEdge(g, src, dest);
    }
    printf("\nThe graph is:\n");
    printGraph(g);

    printf("\nBFS: "); BFS(g, 0);
    printf("\nDFS: "); DFS(g, 0);
    printf("\n"); return 0;
}

/*
Enter number of vertices: 5
Enter number of edges: 5
Enter src and dest of edge 1 : 0 1
Enter src and dest of edge 2 : 0 2
Enter src and dest of edge 3 : 1 2
Enter src and dest of edge 4 : 1 3
Enter src and dest of edge 5 : 1 4

The graph is:
Vertex 0 is connected to: 2 1 NULL
Vertex 1 is connected to: 4 3 2 0 NULL
Vertex 2 is connected to: 1 0 NULL
Vertex 3 is connected to: 1 NULL
Vertex 4 is connected to: 1 NULL

BFS: 0 2 1 4 3
DFS: 0 1 4 3 2
*/
