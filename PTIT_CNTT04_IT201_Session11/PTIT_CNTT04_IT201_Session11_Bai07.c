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
int getLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

Node* insertNodeAtHead(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

Node* insertNodeAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

Node* insertNodeAtPosition(Node* head, int data, int position) {
    if (position < 1 || position > getLength(head)) {
        printf("Vi tri khong hop le\n");
        return head;
    }
    if (position == 1) {
        return insertNodeAtHead(head, data);
    }
    if (position == getLength(head)) {
        return insertNodeAtEnd(head, data);
    }
    Node* current = head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    Node* newNode = createNode(data);
    Node* prev = current->prev;
    newNode->next = current;
    current->prev = newNode;
    prev->next = newNode;
    newNode->prev = prev;
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
    int value, position;
    printf("Nhap gia tri can them:");
    scanf("%d", &value);
    printf("Nhap vi tri van them:");
    scanf("%d", &position);
    node1 = insertNodeAtPosition(node1, value, position);
    printList(node1);
    Node* current = node1;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }


    return 0;
}