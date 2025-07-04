#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}
void printNode(Node* node) {
    while ( node != NULL) {
        printf("Data: %d\n", node->data);
        node = node->next;
    }

}
Node* insertEnd(Node* node, int value) {
    Node* newNode = createNode(value);
    if (node == NULL) return newNode;

    Node* current = node;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return node;
}
int main() {
    Node *head = createNode(5);
    Node *node1 = createNode(4);
    Node *node2 = createNode(3);
    Node *node3 = createNode(2);
    Node *node4 = createNode(1);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;
    printNode(head);
    int value;
    printf("Nhap gia tri can them vao mang:");
    scanf("%d", &value);
    head = insertEnd(head, value);
    printNode(head);
    return 0;
}