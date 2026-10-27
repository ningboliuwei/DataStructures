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

int InitQueue(LinkQueue *&Q) {
    //@@1
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
    QNode *newNode = new QNode;
    newNode->data = x;
    newNode->next = NULL;

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
    if (QueueEmpty(Q) == 1) {
        return 0;
    } else {
        QNode *p = Q->front;
        x = Q->front->data;

        if (Q->front == Q->rear) { // 当前节点是唯一元素
            Q->front = NULL;
            Q->rear = NULL;
        } else {
            Q->front = Q->front->next;
        }

        free(p);
    }
    //@@4
}

int main() {
    LinkQueue *Q;
    //@@5
    int choice = -1;
    int x = -1;
    printf("请选择： 1 创建新队列 2 入队 3 出队 0 结束");
    scanf("%d", &choice);

    while (choice != 0) {
        if (choice == 1) {
            InitQueue(Q);
            printf("创建成功");
        } else if (choice == 2) {
            scanf("%d", &x);

            int result = InQueue(Q, x);
            if (result == 1) {
                printf("入队成功");
            } else {
                printf("入队失败");
            }

        } else if (choice == 3) {
            int result = OutQueue(Q, x);

            if (result == 1) {
                printf("%d", x);
                printf("出队成功");
            } else {
                printf("出队失败");
            }
        }
        scanf("%d", &choice);
    }
    //@@5
}