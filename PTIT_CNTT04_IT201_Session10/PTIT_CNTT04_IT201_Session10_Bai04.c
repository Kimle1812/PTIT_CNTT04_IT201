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
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
Node* deleteEnd(Node* node) {
    if (node == NULL) {
        return NULL;
    }
    Node* current = node;
    while (current->next->next != NULL) {
        current = current->next;
    }
    Node* removeNode = current->next;
    current->next = NULL;
    free(removeNode);
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
    head = deleteEnd(head);
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    printNode(head);
    return 0;
}