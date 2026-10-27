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
    Q->front = NULL;
    Q->rear = NULL;
    return 1;
}
int QueueEmpty(LinkQueue *Q) {
    if (Q->front == NULL)
        return 1;
    else
        return 0;
}

int InQueue(LinkQueue *Q, datatype x) {
    struct QNode *s = (struct QNode *)malloc(sizeof(struct QNode));
    s->data = x;
    s->next = NULL;

    if (Q->front == NULL)
        Q->front = s;
    else {
        Q->rear->next = s;
        Q->rear = s;
    }

    return 1;
}

int OutQueue(LinkQueue *Q, datatype &x) {
    if (QueueEmpty(Q) == 1)
        return 0;

    struct QNode *fre = (struct QNode *)malloc(sizeof(struct QNode));
    fre = Q->front;
    Q->front = Q->front->next;
    x = fre->data;
    free(fre);

    return 1;
}

int main() {
    LinkQueue *Q;

    int sca, pri;
    printf("请选择： 1 创建新队列 2 入队 3 出队 0 结束\n");
    scanf("%d", &sca);
    while (sca != 0) {
        switch (sca) {
        case 1:
            if (InitQueue(Q) == 1)
                printf("创建成功\n");
            else
                printf("创建失败\n");
            break;
        case 2:
            scanf("%d", &sca);
            if (InQueue(Q, sca) == 1)
                printf("入队成功", pri);
            else
                printf("入队失败\n");
            break;
        case 3:
            if (OutQueue(Q, pri) == 1)
                printf("%d\n", pri);
            else
                printf("出队失败\n");
            break;
        }
        printf("请选择： 1 创建新队列 2 入队 3 出队 0 结束\n");
        scanf("%d", &sca);
    }
}