#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
    int u, v, w;
} edge;

typedef struct graph {
    int V, E;
    edge *edges;
} graph;

typedef struct subset {
    int parent, rank;
} subset;

int find(subset *subsets, int i) {  // Time complexity: O(logV)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(subset *subsets, int x, int y) { // Time complexity: O(logV)
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int myComp(const void *a, const void *b) {
    edge *a1 = (edge *)a;
    edge *b1 = (edge *)b;
    return a1->w > b1->w;
}

void KruskalMST(graph *G) {
    int V = G->V;
    edge result[V];
    qsort(G->edges, G->E, sizeof(G->edges[0]), myComp); // Time complexity: O(ElogE)
    subset *subsets = (subset *)malloc(V * sizeof(subset));
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int e = 0, i = 0;
    while (e < V-1 && i < G->E) {   // Time complexity: O(ElogV)
        edge next_edge = G->edges[i++];
        int x = find(subsets, next_edge.u);
        int y = find(subsets, next_edge.v);
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y); 
        }
    }
    printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].w);
    return;
}

int main() {
    graph *G = (graph *)malloc(sizeof(graph));
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &G->V, &G->E);
    G->edges = (edge *)malloc(G->E * sizeof(edge));

    printf("Enter the edges (u v w): ");
    for (int i = 0; i < G->E; ++i)
        scanf("%d %d %d", &G->edges[i].u, &G->edges[i].v, &G->edges[i].w);
    
    printf("Kruskal's MST:\n");
    KruskalMST(G);
    return 0;
}
