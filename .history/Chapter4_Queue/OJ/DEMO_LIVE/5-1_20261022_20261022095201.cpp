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
    Q->front = NULL;
    Q->rear = NULL;
    //@@1

    return 1;
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
    newNode->next = NULL;
    newNode->data = x;

    if (QueueEmpty(Q) == 1) {
        Q->front = newNode;
        Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }

    //@@3
}

int OutQueue(LinkQueue *Q, datatype &x) {
    //@@4
    x = Q->front->data;

    if (Q->front == Q->rear && Q->front != NULL) {
        Q->front = NULL;
        Q->rear = NULL;
    } else {
        Q->front = Q->front->next;
    }

    free(Q->front);

    //@@4
}

int main() {
    LinkQueue *Q;
    //@@5
    int choice = -1;
    scanf("%d", &choice);

    while (choice != 0) {
        if (choice == 1) {
            InitQueue(Q);
        }
    }
    //@@5
}