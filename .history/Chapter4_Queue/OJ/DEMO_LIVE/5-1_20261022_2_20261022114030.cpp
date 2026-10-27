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
        QNode *p = Q->front;
        x = p->data;

        if (Q->front == Q->rear) {
            Q->front = NULL;
            Q->rear = NULL;
        } else {
            x = Q->front->data;
            Q->front = Q->front->next;
        }
        free(p);

        return 1;
    }
    //@@4
}

int main() {
    LinkQueue *Q;
    //@@5
    //@@5
    printf("请选择： 1 创建新队列 2 入队 3 出队 0 结束\n");
    int choice = -1;
    scanf("%d", &choice);

    while (choice != 0) {
        if (choice == 1) {
            InitQueue(Q);

            if (Q != NULL) {
                printf("创建成功\n");
            } else {
                printf("创建失败\n");
            }
        } else if (choice == 2) {
            int x;
            scanf("%d", &x);
            int result = InQueue(Q, x);

            if (result == 1) {
                printf("入队成功\n");
            } else {
                printf("入队失败\n");
            }
        } else if (choice == 3) {
            int x;
            int result = OutQueue(Q, x);

            if (result == 0) {
                printf("出队失败\n");
            } else {
                printf("%d\n", x);
            }
        }
    }
}