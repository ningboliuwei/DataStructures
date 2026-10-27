
#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

typedef struct QNodeStruct {
    datatype data;
    struct QNodeStruct *next;
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

void InQueue(LinkQueue *&Q, datatype x) {
    QNode *s = (QNode *)malloc(sizeof(QNode));
    s->next = NULL;
    s->data = x;

    if (Q->front == NULL && Q->rear == NULL) {
        Q->front = s; // 1
        Q->rear = s;  // 2
    } else {
        Q->rear->next = s; // 3
        Q->rear = s;       // 4
    }
}

int main() {
    LinkQueue *queue;
    InitQueue(queue);
    InQueue(queue, 3);
    InQueue(queue, 4);
    InQueue(queue, 5);
}