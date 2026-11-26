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

void CreateGraph(MGraph *g) {
    char vex1;
    char vex2;
    int weight;
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
        g->edges[pos1][pos2] = weight;
        g->edges[pos2][pos1] = weight;
    }
}

void DFSM(MGraph *g, int nodeIndex, int *visited) {
    // 输出访问的顶点
    printf("%d ", g->vexs[nodeIndex]);
    // 在 visited 数组中将该顶点标记为“已访问”
    visited[nodeIndex] = 1;
    // 针对当前顶点所有尚未被访问的邻接点，递归调用 DFSM 函数
    for (int i = 0; i < g->n; i++) {
        if (g->edges[nodeIndex][i] == 1 && !visited[i]) {
            DFSM(g, i, visited);
        }
    }
}

void DFSTraverseM(MGraph *g) {
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
            DFSM(g, i, visited);
        }
    }
}

int main() {
    MGraph *g = (MGraph *)malloc(sizeof(MGraph));
    CreateGraph(g);
    DFSTraverseM(g);

    getchar();
    getchar();
}