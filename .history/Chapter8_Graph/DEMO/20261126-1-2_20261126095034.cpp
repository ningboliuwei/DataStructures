#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10

typedef int dataType;

typedef struct SequenceQueueType {
    int data[MAXLEN];
    int front;
    int rear;
} SequenceQueue;

int InitQueue(SequenceQueue *&Q) {
    Q->front = -1;
    Q->rear = -1;

    return 1;
}

int QueueEmpty(SequenceQueue *Q) {
    if (Q->front == Q->rear) {
        return 1;
    }
    return 0;
}

int InQueue(SequenceQueue *Q, dataType x) {
    if (Q->rear == MAXLEN - 1) {
        return 0;
    }

    Q->data[++Q->rear] = x;
}

int OutQueue(SequenceQueue *Q, dataType x) {
    if (QueueEmpty(Q)) {
        return 0;
    }

    x = Q->data[Q->front++];
}

typedef struct {
    char vexs[MAXLEN];
    int edges[MAXLEN][MAXLEN];
    // 顶点个数
    int n;
    // 边数
    int e;
} MGraph;

void CreateGraph(MGraph *g) {
    char vex1;
    char vex2;
    int pos1;
    int pos2;

    // 对邻接矩阵进行初始化
    for (int i = 0; i < MAXLEN; i++) {
        for (int j = 0; j < MAXLEN; j++) {
            g->edges[i][j] = 0;
        }
    }

    scanf("%d %d\n", &(g->n), &(g->e));

    for (int i = 0; i < g->n; i++) {
        char c;
        scanf("\n%c", &c);
        g->vexs[i] = c;
    }
    // 循环边的条数次
    for (int i = 0; i < g->e; i++) {
        scanf("\n%c %c", &vex1, &vex2);
        // 找起点行号
        for (pos1 = 0; pos1 < g->n; pos1++) {
            if (g->vexs[pos1] == vex1) {
                break;
            }
        }
        // 找终点行号
        for (pos2 = 0; pos2 < g->n; pos2++) {
            if (g->vexs[pos2] == vex2) {
                break;
            }
        }
        g->edges[pos1][pos2] = 1;
        g->edges[pos2][pos1] = 1;
    }
}

void BFSM(MGraph *g, int nodeIndex, int *visited) {
    SequenceQueue *Q = (SequenceQueue *)malloc(sizeof(SequenceQueue));
    InitQueue(Q);

    printf("%c ", g->vexs[nodeIndex]);
    visited[nodeIndex] = 1;

    InQueue(Q, nodeIndex);

    while (!QueueEmpty(Q)) {
        int x;
        OutQueue(Q, x);

        for (int i = 0; i < g->n; i++) {
            if (g->edges[x][i] == 1 && !visited[i]) {
                printf("%c ", g->vexs[i]);
                visited[i] = 1;
                InQueue(Q, i);
            }
        }
    }
}

void BFSTraverseM(MGraph *g) {
    // 用于记录哪些顶点已经被访问了
    int visited[g->n];
    // 初始化 visted 数组
    for (int i = 0; i < g->n; i++) {
        visited[i] = 0;
    }

    printf("DFS ");
    for (int i = 0; i < g->n; i++) {
        // 若当前顶点尚未被访问过
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