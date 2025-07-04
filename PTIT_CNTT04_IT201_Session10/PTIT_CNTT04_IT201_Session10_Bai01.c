#include<stdio.h>
#include<stdlib.h>
 typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);;
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    return 0;
}