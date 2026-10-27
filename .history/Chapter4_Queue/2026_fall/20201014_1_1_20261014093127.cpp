
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
        Q->front = s;
        Q->rear = s;
    } else {
        Q->rear->next = s;
    }
}

int main() {
    LinkQueue *queue;
    InitQueue(queue);
}