#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
}stack;

void initStack(stack* s) {
    s->top = NULL;
}

int isEmpty(stack* s) {
    return s->top == NULL;
}

void push(stack *s,int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(stack *s) {
    if (isEmpty(s)) {
        printf("Ngan xep rong");
        return -1;
    }
    Node* temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

void printStack(stack *s) {
    if (isEmpty(s)) {
        printf("Ngan xep rong\n");
        return;
    }
    Node* temp = s->top;
    printf("stack ={\n");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n}\n");
}

int peek(stack *s) {
    if (isEmpty(s)) {
        printf("Ngan xep rong\n");
        return -1;
    }
    return s->top->data;
}

int main(void) {
    stack s;
    initStack(&s);
    int n;
    printf("Nhap phan tu vao ngan xep:");
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        int value;
        printf("Phan tu thu %d:", i + 1);
        scanf("%d",&value);
        push(&s,value);
    }
    printStack(&s);
    int result = peek(&s);
    if (result != -1) {
        printf("Phan tu tren cung co gia tri la:%d", result);
    }
    return 0;
}