#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
typedef int datatype;
typedef struct QNode {
    datatype data;
    struct QNode *next;
} QNode;

typedef struct qptr {
    QNode *front; //队头指针
    QNode *rear;  //队尾指针
} LinkQueue;

void InitQueue(LinkQueue *&Q) {
    //@@1
    Q = (LinkQueue *)malloc(sizeof(LinkQueue));
    Q->front = NULL;
    Q->rear = NULL;

    //@@1
}
int QueueEmpty(LinkQueue *Q) {
    //@@2
    if (Q->front == NULL && Q->rear == NULL) {
        return 1;
    } else {
        return 0;
    }
    //@@2
}

int InQueue(LinkQueue *Q, datatype x) {
    //@@3
    QNode *newNode = (QNode *)malloc(sizeof(QNode));

    if (newNode == NULL) {
        return 0;
    }

    newNode->data = x;
    newNode->next = NULL;

    if (QueueEmpty(Q)) {
        Q->front = newNode;
        Q->rear == newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }

    return 1;
    //@@3
}

int OutQueue(LinkQueue *Q, datatype &x) {
    //@@4
    if (QueueEmpty(Q)) {
        return 0;
    } else {
        x = Q->front->data;
        free(Q->front);

        if (Q->front == Q->rear) {
            Q->front = NULL;
            Q->rear = NULL;
        } else {
            x = Q->front->data;
            free(Q->front);
        }
    }
    //@@4
}

int main() {
    LinkQueue *Q;
    //@@5
    //@@5
}