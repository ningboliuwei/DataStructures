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
    Q = (LinkQueue *)malloc(sizeof(LinkQueue));
    Q->front = NULL;
}
int QueueEmpty(LinkQueue *Q) {
}

int InQueue(LinkQueue *Q, datatype x) {
    QNode *p = new QNode;
    p->data = x;
    p->next = Q->front;
    Q->front = p;
}

int OutQueue(LinkQueue *Q, datatype &x) {
    QNode *p;
    if (Q->front != NULL) {
        p = Q->front;
        x = p->data;
        Q->front = p->next;
        printf("%d\n", x);
        delete p;
        return 1;
    } else
        return 0;
}

int main() {
    LinkQueue *Q;

    int c, m, t;
    while (1) {
        scanf("%d", &c);
        if (c == 0)
            break;

        if (c == 1) {
            InitQueue(Q);
            printf("创建成功\n");
        }
        if (c == 2) {
            scanf("%d", &m);
            InQueue(Q, m);
            printf("入队成功\n");
        }
        if (c == 3) {
            t = OutQueue(Q, m);
            if (t == 1)
                printf("出队成功\n");
            else
                printf("出队失败\n");
        }
        printf("请选择： 1 创建新队列 2 入队 3 出队 0 结束\n");
    }
}