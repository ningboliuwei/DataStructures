#include <stdio.h>
#include <stdlib.h>

// 问题 E: 【数据结构8-5】最小生成树——Prim算法
// ID：1647
// OJ PASSED
// 输入：
// 6 10
// 1
// 2
// 3
// 4
// 5
// 6
// 1 2 6
// 1 3 1
// 1 4 5
// 2 3 5
// 3 4 5
// 2 5 3
// 3 5 6
// 5 6 6
// 3 6 4
// 4 6 2
// 输出：
// 最小生成树
// 1 3 1
// 3 6 4
// 6 4 2
// 3 2 5
// 2 5 3

#define MAX_VEX_COUNT 10
#define MAX_EDGE_COUNT 100
#define INFINITY 99999
typedef struct {
    char vexs[MAX_VEX_COUNT];
    int edges[MAX_VEX_COUNT][MAX_VEX_COUNT];
    // 顶点数
    int n;
    // 边数
    int e;
} MGraph;

typedef struct {
    // 边的起点
    char u;
    // 边的终点
    char v;
    // 边的权值
    int weight;
    // 标志值，其中 0 表示尚未被选中，1 表示被选中，2 表示被淘汰
    int flag;
} EdgeFlag;

void MiniSpanTree_KRUSKAL(MGraph G, int n, int v) {
    // 定义一个名为 vexSets
    // 的数组，用于给每一个顶点设置其所属的集合，可以看成是这个顶点所属的连通分量的编号，用一个整数来表示。初始时，每个顶点分属不同的集合（连通分量）
    int vexSets[MAX_VEX_COUNT];
    // 定义一个名为 edgeFlags 的数组，
    int edgeFlags[MAX_EDGE_COUNT];
    // 初始化 vexFlags 数组
    for (int i = 0; i < G.n; i++) {
        vexSets[i] = i;
    }
    // 初始化 edgeFlags 数组
    for (int i = 0; i < G.e; i++) {
        edgeFlags[i] = 0;
    }

    int min = INFINITY;
    // 找出所有边里权值最小的那个
    for (int i = 0; i < G.n; i++) {
        for (int j = 0; j < G.n; j++) {
            if (G.edges[i][j] < min) {
                min = G.edges[i][j];
            }
        }
    }
} // Min

void CreateGraph(MGraph *g) {
    char vex1;
    char vex2;
    int weight;
    int pos1;
    int pos2;

    for (int i = 0; i < MAX_VEX_COUNT; i++) {
        for (int j = 0; j < MAX_VEX_COUNT; j++) {
            if (i == j) {
                g->edges[i][j] = 0;
            } else {
                g->edges[i][j] = INFINITY;
            }
        }
    }

    scanf("%d %d\n", &(g->n), &(g->e));

    for (int i = 0; i < g->n; i++) {
        char c;
        scanf("\n%c", &c);
        g->vexs[i] = c;
    }

    for (int i = 0; i < g->e; i++) {
        scanf("\n%c %c %d", &vex1, &vex2, &weight);

        for (pos1 = 0; pos1 < g->n; pos1++) {
            if (g->vexs[pos1] == vex1) {
                break;
            }
        }

        for (pos2 = 0; pos2 < g->n; pos2++) {
            if (g->vexs[pos2] == vex2) {
                break;
            }
        }

        g->edges[pos1][pos2] = weight;
        // 无向网要加下面一行（基于对角线对称）
        g->edges[pos2][pos1] = weight;
    }
}

int main() {
    MGraph *g = (MGraph *)malloc(sizeof(MGraph));

    CreateGraph(g);
    printf("最小生成树\n");
    MiniSpanTree_KRUSKAL(*g, g->n, 0);

    getchar();
    getchar();
}
