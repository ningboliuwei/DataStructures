#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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

int InitQueue(LinkQueue *&Q) {

    Q->front = NULL;
    Q->rear = NULL;
    return 1;
}
int QueueEmpty(LinkQueue *Q) {

    if (Q->front == NULL) {
        return 0;
    }
    return 1;
}

int InQueue(LinkQueue *Q, datatype x) {

    QNode *p;
    p = (QNode *)malloc(sizeof(QNode));
    p->next = NULL;
    p->data = x;
    if (Q->front == NULL) {
        Q->front = p;
        Q->rear = p->next;
    } else {
        Q->rear = p;
        Q->rear = p->next;
    }
    printf("入队成功\n");
    return 1;
}

int OutQueue(LinkQueue *Q, datatype &x) {

    if (QueueEmpty(Q) == 1) {
        x = Q->front->data;
        Q->front = Q->front->next;
        printf("%d", x);
        printf("出队成功\n");
        return 1;
    } else {
        printf("出队失败\n");
        return 0;
    }
}

int main() {
    LinkQueue *Q;

    int x, y;
    InitQueue(Q);
    printf("请选择： 1 创建新队列 2 入队 3 出队 0 结束\n");
    scanf("%d", &x);
    while (x != 0) {
        if (x == 1) {
            InitQueue(Q);
            printf("创建成功\n");
        }
        if (x == 2) {
            scanf("%d", &y);
            InQueue(Q, y);
        }
        if (x == 3) {
            OutQueue(Q, y);
        }
        printf("请选择： 1 创建新队列 2 入队 3 出队 0 结束\n");
        scanf("%d", &x);
    }
    return 1;
}