
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

int IsQueueEmpty(LinkQueue *&Q) {
    if (Q->front == NULL && Q->rear == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int InQueue(LinkQueue *&Q, datatype x) {
    QNode *s = (QNode *)malloc(sizeof(QNode));
    s->next = NULL;
    s->data = x;

    if (IsQueueEmpty(Q)) {
        Q->front = s; // 1
    } else {
        Q->rear->next = s; // 3
    }
    Q->rear = s; // 2

    return 1;
}
int OutQueue(LinkQueue *&Q, datatype &x) {
    if (IsQueueEmpty(Q)) {
        return 0;
    } else {
        QNode *p = Q->front;
        x = p->data;
        if (Q->front == Q->rear && Q->front != NULL) {
            Q->front = NULL;
            Q->rear = NULL;
        } else {
            Q->front = p->next;
        }

        free(p);
    }
}

int main() {
    LinkQueue *queue;
    InitQueue(queue);
    InQueue(queue, 3);
    InQueue(queue, 4);
    InQueue(queue, 5);
    int x;
    OutQueue(queue, x);
    OutQueue(queue, x);
    OutQueue(queue, x);
}