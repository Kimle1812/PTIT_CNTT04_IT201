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

Node* deleteNodeAtHead(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* current = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(current);
    return head;
}

Node* deleteNodeAtEnd(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
    return head;
}

Node* deleteNodeAtPosition(Node* head, int position) {
    if (position < 1 || position > getLength(head)) {
        printf("Vi tri khong hop le\n");
        return NULL;
    }
    if (position == 1) {
        return deleteNodeAtHead(head);
    }
    if (position == getLength(head)) {
        return deleteNodeAtEnd(head);
    }
    Node* current = head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    Node* prev = current->prev;
    Node* next = current->next;
    Node* temp = current;
    prev->next = next;
    next->prev = prev;
    free(temp);
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

    int position;
    printf("Nhap vi tri can xoa:");
    scanf("%d", &position);
    node1 = deleteNodeAtPosition(node1, position);
    printList(node1);
    Node* current = node1;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}