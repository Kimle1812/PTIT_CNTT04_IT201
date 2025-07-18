#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int front;
    int rear;
    int capacity;
} Queue;

Queue createQueue(int capacity) {
    Queue q;
    q.array = (int *)malloc(capacity * sizeof(int));
    q.front = 0;
    q.rear = -1;
    q.capacity = capacity;
    return q;
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}
int isFull(Queue *q) {
    return q->rear == q->capacity - 1;
}
void enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Hang doi da day\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = value;
}
void displayQueue(Queue q) {
    if (isEmpty(&q)) {
        printf("Hang doi trong\n");
        return;
    }
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d\n", q.array[i]);
    }
}

int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Hang doi trong\n");
        return -1;
    }
    int value = q->array[q->front];
    q->front++;
    return value;
}

int main() {
    Queue queue2 = createQueue(5);
    enqueue(&queue2, 1);
    enqueue(&queue2, 2);
    enqueue(&queue2, 5);

    int removed = dequeue(&queue2);
    printf("return value = %d\n", removed);

    printf("Trang thai hang doi sau khi dequeue:\n");
    displayQueue(queue2);

    free(queue2.array);
    return 0;
}