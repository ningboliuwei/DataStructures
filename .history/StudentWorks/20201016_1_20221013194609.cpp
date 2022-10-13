#include <stdio.h>
#include <stdlib.h>

using namespace std;
typedef int datatype;
typedef struct QueueNode {
    datatype data;
    struct QueueNode *next;
} QueueNode;

typedef struct qptr {
    QueueNode *front; //��ͷָ��
    QueueNode *rear;  //��βָ��
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
    QueueNode *p;
    p = (QueueNode *)malloc(sizeof(QueueNode));
    p->next = NULL;
    p->data = x;
    if (Q->front == NULL) {
        Q->front = p;
        Q->rear = p->next;
    } else {
        Q->rear = p;
        Q->rear = p->next;
    }
    printf("��ӳɹ�\n");
    return 1;
}

int OutQueue(LinkQueue *Q, datatype &x) {
    if (QueueEmpty(Q) == 1) {
        x = Q->front->data;
        Q->front = Q->front->next;
        printf("%d", x);
        printf("���ӳɹ�\n");
        return 1;
    } else {
        printf("����ʧ��\n");
        return 0;
    }
}

int main() {
    LinkQueue *Q;

    int x, y;
    InitQueue(Q);
    printf("��ѡ�� 1 �����¶��� 2 ��� 3 ���� 0 ����\n");
    scanf("%d", &x);
    while (x != 0) {
        if (x == 1) {
            InitQueue(Q);
            printf("�����ɹ�\n");
        }
        if (x == 2) {
            scanf("%d", &y);
            InQueue(Q, y);
        }
        if (x == 3) {
            OutQueue(Q, y);
        }
        printf("��ѡ�� 1 �����¶��� 2 ��� 3 ���� 0 ����\n");
        scanf("%d", &x);
    }
    return 1;
}