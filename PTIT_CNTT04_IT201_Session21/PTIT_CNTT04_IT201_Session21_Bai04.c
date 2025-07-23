#include <stdio.h>
#define SIZE 3

void addEdge(int graph[SIZE][SIZE], int startNode, int endNode) {
    graph[startNode][endNode] = 1;
}

void printGraph(int graph[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[SIZE][SIZE] = {{0}};
    int startNode, endNode;

    for (int i = 0; i < SIZE; i++) {
        printf("Nhap so bat dau: ");
        scanf("%d", &startNode);
        printf("Nhap so ket thuc: ");
        scanf("%d", &endNode);
        addEdge(graph, startNode, endNode);
    }

    printGraph(graph);

    return 0;
}
