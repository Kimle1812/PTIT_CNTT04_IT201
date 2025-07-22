#include <stdio.h>
#include <stdlib.h>

// Cấu trúc Node
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Cấu trúc Queue dùng mảng con trỏ Node*
typedef struct Queue {
    Node **arr;
    int capacity;
    int front;
    int rear;
} Queue;

// Tạo Queue
Queue *createQueue(int capacity) {
    Queue *q = malloc(sizeof(Queue));
    q->arr = malloc(sizeof(Node*) * capacity);
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    return q;
}

// Kiểm tra rỗng
int isEmpty(Queue* q) {
    return q->front > q->rear;
}

// Kiểm tra đầy
int isFull(Queue* q) {
    return q->rear + 1 == q->capacity;
}

// Thêm phần tử
void enqueue(Queue* q, Node* node) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->arr[++q->rear] = node;
}

Node* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL;
    return q->arr[q->front++];
}

Node* createNode(int data) {
    Node *n = malloc(sizeof(Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

int search(Node *root, int target) {
    if (root == NULL) return 0;

    Queue* q = createQueue(100);
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        if (current->data == target) {
            free(q->arr);
            free(q);
            return 1;
        }
        if (current->left) enqueue(q, current->left);
        if (current->right) enqueue(q, current->right);
    }

    free(q->arr);
    free(q);
    return 0;
}

int main() {
    Node *root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int value;
    printf("Enter the value: ");
    scanf("%d", &value);

    int flag = search(root, value);
    if (flag == 1)
        printf("True\n");
    else
        printf("False\n");

    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
