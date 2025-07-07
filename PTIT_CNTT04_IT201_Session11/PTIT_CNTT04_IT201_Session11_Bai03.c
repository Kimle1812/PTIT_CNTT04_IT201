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
Node* searchData(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
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
    printList(node1);
    int search;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &search);
    int flag = searchData(node1, search);
    if (flag == NULL) {
        printf("False");
    }else {
        printf("True");
    }
    return 0;
}