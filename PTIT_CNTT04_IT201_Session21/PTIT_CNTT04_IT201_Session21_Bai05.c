#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

// Cấu trúc node trong danh sách liên kết
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* graph[SIZE], int startNode, int endNode) {
    Node* newNode = createNode(endNode);
    newNode->next = graph[startNode];  // chèn vào đầu danh sách
    graph[startNode] = newNode;
}

void printGraph(Node* graph[SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d: ", i);
        Node* temp = graph[i];
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    Node* graph[SIZE] = {NULL};

    addEdge(graph, 1, 2);
    addEdge(graph, 2, 1);
    addEdge(graph, 2, 0);
    addEdge(graph, 0, 1);

    printGraph(graph);

    return 0;
}
