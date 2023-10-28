//
// Created by Liu Wei on 2018/10/8.
// 1610 问题 A: 【数据结构4-1】链队列基本操作P77
// OJ PASSED

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
typedef int dataType;
typedef struct QueueNode {
    dataType data;
    struct QueueNode *next;
} QueueNode;

typedef struct qptr {
    QueueNode *front; //队头指针
    QueueNode *rear;  //队尾指针
} LinkQueue;

int InitQueue(LinkQueue *&Q) {
    //@@1
    Q = new LinkQueue;
    Q->front = NULL;
    Q->rear = NULL;

    return 1;
    //@@1
}

int QueueEmpty(LinkQueue *Q) {
    //    @@2
    if (Q->front == NULL && Q->rear == NULL) {
        return 1;
    }
    return 0;
    //    @@2
}

int InQueue(LinkQueue *Q, dataType x) {
    //    @@3
    QueueNode *newNode = new QueueNode;
    newNode->data = x;
    newNode->next = NULL;

    // if (QueueEmpty(Q) == 1){
    // if (Q->front == NULL && Q->rear == NULL){
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

int main() {
    LinkQueue *Q;
    //    @@5
    int choice = -1;
    int x = 0;
    while (1) {
        printf("请选择： 1 创建新队列 2 入队 3 出队 0 结束\n");
        scanf("%d", &choice);
        if (choice == 0) {
            return 0;
        } else if (choice == 1) {
            if (InitQueue(Q) == 1) {
                printf("创建成功\n");
            };
        } else if (choice == 2) {
            scanf("%d", &x);
            if (InQueue(Q, x) == 1) {
                printf("入队成功\n");
            }
        } else if (choice == 3) {
            if (OutQueue(Q, x) == 1) {
                printf("%d\n", x);
                printf("出队成功\n");
            } else {
                printf("出队失败\n");
            }
        }
    }
    //    @@5
}
