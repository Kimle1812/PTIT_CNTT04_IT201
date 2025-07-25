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
        printf("Rong");
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
        printf("Empty");
        return;
    }
    Node* temp = s->top;
    printf("stack ={\n");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n}");
}

void addElement(stack *s) {
    int x;
    printf("Enter element:");
    scanf("%d", &x);
    if (x < 0) {
        printf("Invalid Input");
        return;
    } else {
        push(s,x);
    }
}

int main(void) {
    stack s;
    initStack(&s);
    int n;
    printf("Nhap gia tri phan tu vao ngan xep:");
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        int value;
        printf("Gia tri phan tu:");
        scanf("%d",&value);
        push(&s,value);
    }
    printStack(&s);
    addElement(&s);
    printStack(&s);
    return 0;
}