//
// Created by Liu Wei on 2018/10/8.
// 问题 B: 【数据结构4-2】循环队列基本操作

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 5

typedef int dataType;

typedef struct {
    dataType data[MAXLEN];
    int front; // 头指针
    int rear;  // 尾指针
} SeqQueue;

int InitQueue(SeqQueue *&Q) {
    //@@1
    Q = new SeqQueue;
    Q->front = -1;
    Q->rear = -1;

    return 1;
    //@@1
}

int QueueEmpty(SeqQueue *Q) {
    //    @@2
    if (Q->front == Q->rear) { return 1; }

    return 0;
    //    @@2
}

int InQueue(SeqQueue *Q, dataType x) {
    //    @@3
    if (Q->front == (Q->rear + 1) % MAXLEN) { return 0; }
    Q->front = (Q->front + 1) % MAXLEN;
    Q->rear = (Q->rear + 1) % MAXLEN;
    Q->data[Q->rear] = x;

    return 1;
    //    @@3
}

int OutQueue(SeqQueue *Q, dataType &x) {
    //@@4
    if (QueueEmpty(Q)) { return 0; }

    Q->front = (Q->front + 1) % MAXLEN;
    x = Q->data[Q->front];

    return 1;
    //@@4
}

int main() {
    SeqQueue *Q;
    //    @@5
    int choice = -1;
    int x = 0;
    while (1) {
        printf("请选择： 1 创建新队列 2 入队 3 出队 0 结束\n");
        scanf("%d", &choice);
        if (choice == 0) {
            return 0;
        } else if (choice == 1) {
            if (InitQueue(Q) == 1) { printf("创建成功\n"); };
        } else if (choice == 2) {
            scanf("%d", &x);
            if (InQueue(Q, x) == 1) {
                printf("入队成功\n");
            } else {
                printf("入队失败");
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