#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int **matrix;
    int V;
} Graph;

Graph* createGraph(int V) {
    Graph *graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->matrix = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = (int*)calloc(V, sizeof(int));
    }
    return graph;
}
void addEdge(Graph* graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}
void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int src;
    printf("Nhap so luong dinh: ");
    scanf("%d", &src);
    Graph *graph = createGraph(src);
    int firstNode, secondNode;
    for (int i = 0; i < 6; i++) {
        printf("Nhap so thu nhat: ");
        scanf("%d", &firstNode);
        printf("Nhap so thu hai: ");
        scanf("%d", &secondNode);
        addEdge(graph, firstNode, secondNode);
    }
    printGraph(graph);
    return 0;
}