#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preorder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
    return;
}

void postorder(Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
    return;
}

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
    return;
}
typedef struct Queue {
    Node **arr;
    int capacity;
    int front;
    int rear;
} Queue;

//Hàm khởi tạo hàng đợi
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->arr = (Node**)malloc(sizeof(Node*) * capacity);
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

//Xây dựng hàm kiểm tra hàng đợi trống
int isQueueEmpty(Queue* queue) {
    if (queue->front > queue->rear) {
        return 1;
    }
    return 0;
}
//Xây dựng hàm thêm phần tử vào hàng đợi
void enqueue(Queue* queue, Node* node) {
    if (queue -> rear == queue -> capacity) {
        printf("Hang doi day");
        return;
    }
    queue -> rear++;
    queue -> arr[queue -> rear] = node;
}

//Xây dựng hàm duyệt theo chiều rộng BFS
void levelOrderBFS(Node* root) {
    //Kiểm tra cây rỗng
    if (root == NULL) {
        printf("Cay rong");
        return;
    }
    //Khởi tạo hàng đợi
    Queue* queue = createQueue(100);
    //Đưa root vòa hàng đợi
    enqueue(queue, root);
    //Thực hiện vòng lặp đến khi hàng đợi trống
    while (!isQueueEmpty(queue)) {
        //Lấy node ra khỏi hàng đợi và in ra
        Node* node = queue -> arr[queue -> front++];
        printf("%d ", node -> data);
        //Kiểm tra và thêm con bên trái vào hàng đợi
        if (node -> left != NULL) {
            enqueue(queue,node -> left);
        }
        //Kiểm tra và thêm con bên phải vào hàng đợi
        if (node -> right != NULL) {
            enqueue(queue,node -> right);
        }

    }

}
int main() {
    Node *root = createNode(2);
    Node *node1 = createNode(3);
    Node *node2 = createNode(4);
    Node *node3 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;

    printf("PreOrder: \n");
    preorder(root);

    printf("\nPostOrder: \n");
    postorder(root);

    printf("\nInOrder: \n");
    inorder(root);

    printf("\nLevelOrder: \n");
    levelOrderBFS(root);
    return 0;
}