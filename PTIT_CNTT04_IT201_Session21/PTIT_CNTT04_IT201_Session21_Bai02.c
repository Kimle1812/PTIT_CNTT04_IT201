#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

void addEdge(int graph[SIZE][SIZE], int firstNode, int secondNode ) {
    graph[firstNode][secondNode] = 1;
    graph[secondNode][firstNode] = 1;
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

    int firstNode, secondNode;
    for (int i = 0; i < 4; i++) {
        printf("Nhap so thu nhat: ");
        scanf("%d", &firstNode);
        printf("Nhap so thu hai: ");
        scanf("%d", &secondNode);
        addEdge(graph, firstNode, secondNode);
    }
    printGraph(graph);
    return 0;
}