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
}
int QueueEmpty(LinkQueue *Q) {
    if (Q->rear == NULL && Q->front == NULL)
        return 1;
    else
        return 0;
}

int InQueue(LinkQueue *Q, datatype x) {
    QNode *p = new QNode;
    p->data = x;
    p->next = NULL;
    if (Q->front == NULL)
        Q->front = p;
    else
        Q->rear->next = p;
    Q->rear = p;
}

int OutQueue(LinkQueue *Q, datatype &x) {
    QNode *p = Q->front;
    if (Q->front == NULL) {
        cout << "出队失败" << endl;
        return 0;
    }

    else {
        Q->front = p->next;
        if (Q->front == NULL)
            Q->rear = NULL;
        x = p->data;
        delete p;
        return 1;
    }
}

int main() {
    LinkQueue *Q;

    int n = 5;
    int num;
    int m;
    while (n != 0) {
        cout << "请选择： 1 创建新队列 2 入队 3 出队 0 结束" << endl;
        cin >> n;
        switch (n) {
        case 0: break;
        case 1:
            Q = new LinkQueue;
            InitQueue(Q);

            cout << "创建成功" << endl;
            // getchar();
            break;
        case 2:
            cin >> num;
            InQueue(Q, num);
            cout << "入队成功" << endl;
            // getchar();
            break;
        case 3:

            if (OutQueue(Q, m) == 1) {
                cout << m << endl;
                cout << "出队成功" << endl;
                // getchar();
            }

            break;
        }
    }
}