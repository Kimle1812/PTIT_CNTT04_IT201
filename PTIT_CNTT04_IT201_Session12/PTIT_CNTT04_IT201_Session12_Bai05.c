#include<stdio.h>
#include<stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Gia tri khong dung");
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
Node* deleteValue(Node* head, int value) {
    while (head && head->data == value) {
        Node* node = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        free(node);
    }
    Node* current = head;
    while (current != NULL) {
        if(current->data == value) {
            Node* del = current;
            Node* left = current->prev;
            Node* right = current->next;

            if (left != NULL) left->next = right;
            if (right != NULL) right->prev = left;
            current = right;
            free(del);
        } else {
            current = current->next;
        }
    }
    return head;
}
int main() {
    Node* node1 = createNode(5);
    Node* node2 = createNode(10);
    Node* node3 = createNode(15);
    Node* node4 = createNode(20);
    Node* node5 = createNode(25);
    node1->next = node2;
    node2->prev = node1;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    node4->next = node5;
    node5->prev = node4;
    int value;
    printf("Nhap gia tri muon xoa:");
    scanf("%d", &value);
    node1 = deleteValue(node1, value);
    printList(node1);
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}