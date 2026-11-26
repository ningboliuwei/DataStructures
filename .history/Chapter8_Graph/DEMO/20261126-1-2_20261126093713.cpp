#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10

typedef int dataType;

typedef struct SequenceQueueType {
    int data[MAXLEN];
    int front;
    int rear;
} SequenceQueue;

int InitQueue(SequenceQueue *&Q) {
    Q->front = -1;
    Q->rear = -1;

    return 1;
}

int QueueEmpty(SequenceQueue *Q) {
    if (Q->front == Q->rear) {
        return 1;
    }
    return 0;
}

int InQueue(LinkQueue *Q, dataType x) {
    //    @@3
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->data = x;
    newNode->next = NULL;

    if (Q->rear == NULL) {
        Q->front = newNode;
        Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }

    return 1;
    //    @@3
}

int OutQueue(LinkQueue *Q, dataType &x) {
    //@@4
    if (QueueEmpty(Q)) {
        return 0;
    }

    QueueNode *p = Q->front;
    x = Q->front->data;
    Q->front = Q->front->next;
    // 表示队列中只有一个元素
    if (Q->rear == p) {
        Q->rear = NULL;
    }

    free(p);

    return 1;
    //@@4
}

int QueueLength(LinkQueue *Q) {
    if (QueueEmpty(Q)) {
        return 0;
    };

    QueueNode *node = Q->front;
    int count = 0;
    while (node) {
        count++;
        node = node->next;
    }
    return count;
}
