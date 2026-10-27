
#include <stdio.h>
#include <stdlib.h>

typedef int QElemType;

typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode;

typedef struct {
    QNode *front;
    QNode *rear;
} LinkQueue;

void InitQueue(LinkQueue *&Q) {
    Q = (LinkQueue *)malloc(sizeof(LinkQueue));
    Q->front = NULL;
    Q->rear = NULL;
}

int main() {
    LinkQueue *queue;
    InitQueue(queue);
}