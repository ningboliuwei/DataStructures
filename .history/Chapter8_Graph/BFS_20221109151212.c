//
// Created by Liu Wei on 2018/11/25.
// ���� B: �����ݽṹ8-4��ͼ�ı�������BFS
/*
8,9
1
2
3
4
5
6
7
8
9
1,2
1,3
2,4
2,5
3,6
3,7
4,8
5,8
6,7
BFS: 1 2 4 8 5 3 6 7
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10

typedef int VertexType;

typedef struct {
    VertexType vertex[MAXLEN];
    int edges[MAXLEN][MAXLEN];
    // ������
    int n;
    // ����
    int e;
} MGraph;

typedef struct SequenceQueueType {
    int data[MAXLEN];
    int front;
    int rear;
} * SequenceQueue;

int IsEmptyQueue(SequenceQueue queue) {
    if (queue->rear - queue->front == 0) {
        return 1;
    }

    return 0;
}

int LengthOfQueue(SequenceQueue queue) {
    if (IsEmptyQueue(queue)) {
        return 0;
    }

    return queue->rear - queue->front + 1;
}

int InQueue(SequenceQueue *queue, int item) {
    if ((*queue)->rear == MAXLEN - 1) {
        return 0;
    }

    if (IsEmptyQueue(*queue)) {
        (*queue)->front = 0;
    }

    (*queue)->rear++;
    (*queue)->data[(*queue)->rear] = item;

    return 1;
}

int OutQueue(SequenceQueue *queue, int *item) {
    if (IsEmptyQueue(*queue)) {
        return 0;
    }

    *item = (*queue)->data[(*queue)->front];
    (*queue)->front++;

    return 1;
}

int InitQueue(SequenceQueue *queue) {
    // �˴� sizeof �Ĳ���Ҫע��
    *queue = (SequenceQueue)malloc(sizeof(struct SequenceQueueType));

    (*queue)->front = -1;
    (*queue)->rear = -1;

    return 1;
}

void ShowQueue(SequenceQueue queue) {
    printf("items: ");

    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->data[i]);
    }
    printf("\n");
}

void CreateGraph(MGraph *g) {
    VertexType vex1;
    VertexType vex2;
    int pos1;
    int pos2;

    for (int i = 0; i < MAXLEN; i++) {
        for (int j = 0; j < MAXLEN; j++) {
            g->edges[i][j] = 0;
        }
    }

    // printf("�����붥�����������\n");
    scanf("%d %d\n", &(g->n), &(g->e));

    // printf("����������㣺\n");
    for (int i = 0; i < g->n; i++) {
        VertexType c;
        scanf("\n%d", &c);
        g->vertex[i] = c;
    }

    // printf("������ÿ���߶�Ӧ���������㣺\n");
    for (int i = 0; i < g->e; i++) {
        // printf("�������%d���ߵĶ��㣺", i + 1);
        scanf("\n%d %d", &vex1, &vex2);

        for (pos1 = 0; pos1 < g->n; pos1++) {
            if (g->vertex[pos1] == vex1) {
                break;
            }
        }

        for (pos2 = 0; pos2 < g->n; pos2++) {
            if (g->vertex[pos2] == vex2) {
                break;
            }
        }

        g->edges[pos1][pos2] = 1;
        // ����ͼ�ڽӾ���Գ�
        g->edges[pos2][pos1] = 1;
    }
}

void BFSM(MGraph *g, int nodeIndex, int *visited) {
    SequenceQueue *queue = (SequenceQueue *)malloc(sizeof(SequenceQueue));
    InitQueue(queue);

    printf("%d ", g->vertex[nodeIndex]);
    visited[nodeIndex] = 1;

    InQueue(queue, nodeIndex);

    while (!IsEmptyQueue(*queue)) {
        int currentIndex = (*queue)->front;
        int *item = (int *)malloc(sizeof(int));

        OutQueue(queue, item);

        for (int i = 0; i < g->n; i++) {
            if (g->edges[currentIndex][i] == 1 && !visited[i]) {
                printf("%d ", g->vertex[i]);
                visited[i] = 1;
                InQueue(queue, i);
            }
        }
    }

    return;
}

void BFSTraverseM(MGraph *g) {
    int visited[g->n];

    for (int i = 0; i < g->n; i++) {
        visited[i] = 0;
    }

    printf("BFS ");
    for (int i = 0; i < g->n; i++) {
        if (!visited[i]) {
            BFSM(g, i, visited);
        }
    }
}

int main() {
    MGraph *g = (MGraph *)malloc(sizeof(MGraph));

    CreateGraph(g);
    BFSTraverseM(g);
    getchar();
    getchar();
}