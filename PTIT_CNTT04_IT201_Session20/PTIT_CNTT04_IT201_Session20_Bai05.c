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

int findMax(Node *root) {
    if (root == NULL) {
        return 0;
    }
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    int max = root -> data;
    if (max < leftMax) {
        max = leftMax;
    }
    if (max < rightMax) {
        max = rightMax;
    }
    return max;
}
int main() {
    Node *root = createNode(2);
    Node *node1 = createNode(3);
    Node *node2 = createNode(4);
    Node *node3 = createNode(5);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    printf("Max: %d", findMax(root));
    return 0;
}