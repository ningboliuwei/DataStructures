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
