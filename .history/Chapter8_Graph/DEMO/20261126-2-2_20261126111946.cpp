#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE_COUNT 10

typedef struct {
    char vexs[MAX_NODE_COUNT];
    int edges[MAX_NODE_COUNT][MAX_NODE_COUNT];
    // 顶点个数
    int n;
    // 边数
    int e;
} MGraph;

typedef struct SequenceQueueType {
    int data[MAX_NODE_COUNT];
    int front;
    int rear;
} * SequenceQueue;

int InitQueue(SequenceQueue Q) {
    Q->front = -1;
    Q->rear = -1;
}

int IsEmptyQueue(SequenceQueue Q) {
    if (Q->front == Q->rear) {
        return 1;
    }

    return 0;
}

int InQueue(SequenceQueue Q, int x) {
    if (Q->rear == MAX_NODE_COUNT - 1) {
        return 0;
    }

    Q->data[++Q->rear] = x;
}

int OutQueue(SequenceQueue Q, int &x) {
    if (IsEmptyQueue(Q)) {
        return 0;
    }

    x = Q->data[++Q->front];
}

void CreateGraph(MGraph *g) {
    char vex1;
    char vex2;
    int pos1;
    int pos2;

    // 对邻接矩阵进行初始化
    for (int i = 0; i < MAX_NODE_COUNT; i++) {
        for (int j = 0; j < MAX_NODE_COUNT; j++) {
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
}

void BFSTraverseM(MGraph *g) {
    int visited[g->n];
    // 对 visited 数组进行初始化
    for (int i = 0; i < g->n; i++) {
        visited[i] = 0;
    }

    printf("DFS ");
    // 针对所有当前尚未被访问过的顶点，进行深度遍历
    for (int i = 0; i < g->n; i++) {
        if (!visited[i]) {
            BFSM(g, i, visited);
        }
    }
}

int main() {
    MGraph *g = (MGraph *)malloc(sizeof(MGraph));
    CreateGraph(g);

    getchar();
    getchar();
}
