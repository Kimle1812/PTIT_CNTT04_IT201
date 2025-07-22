#include <stdio.h>
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

//Hàm tìm kiếm trong cây nhị phân sử dụng Depth-first search
int search(Node *root, int value) {
    if (root == NULL) {
        return 0;
    }
    if (root->data == value) {
        return 1;
    }
    return search(root->left, value) || search(root->right, value);
}
int main() {
    Node *root = createNode(2);
    Node *node1 = createNode(3);
    Node *node2 = createNode(4);
    Node *node3 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;


    int value;
    printf("Enter the value: ");
    scanf("%d", &value);
    int flag = search(root, value);
    flag == 1 ? printf("True\n") : printf("False\n");
    return 0;
}