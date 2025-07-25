#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Graph {
    int V;
    Node** adjList;
} Graph;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adjList = (Node**)malloc(V * sizeof(Node*));
    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

void printGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d: ", i);
        Node* temp = graph->adjList[i];
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int V;
    printf("Nhap so luong dinh: ");
    scanf("%d", &V);
    Graph* graph = createGraph(V);

    int u, v;
    for (int i = 0; i < 6; i++) {
        printf("Nhap so thu nhat: ");
        scanf("%d", &u);
        printf("Nhap so thu hai: ");
        scanf("%d", &v);
        addEdge(graph, u, v);
    }

    printGraph(graph);
    return 0;
}
