#include <stdio.h>
#include <stdlib.h>

// 问题 E: 【数据结构8-5】最小生成树——Prim算法
// ID：1647
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
#define INFINITY 99999
typedef struct {
    char vexs[MAX_VEX_COUNT];
    int edges[MAX_VEX_COUNT][MAX_VEX_COUNT];
    // 顶点数
    int n;
    // 边数
    int e;
} MGraph;

void MiniSpanTree_PRIM(MGraph G, int n, int v) {
    // lowcost 数组用于存放 U 集合中到顶点 i（下标）权值最小（路径最短）的那个顶点的边的权值
    int lowcost[MAX_VEX_COUNT];
    // closest 数组用于存放 U 集合中到顶点 i（下标）权值最小（路径最短）的那个顶点的下标
    int closest[MAX_VEX_COUNT];
    int i;
    int j;
    int k;
    int min;

    for (i = 0; i < n; i++) {
        // lowcost 初始值为起点到其他点的权值
        lowcost[i] = G.edges[v][i];
        // close 初始值为起点的下标（形参 v）
        closest[i] = v;
    }
    // 第一步是选出从 U 集合中唯一的点（即起点）出发到 U-V 集合中，权值最小的那个边

    for (i = 0; i < n - 1; i++) {
        min = INFINITY;
        // 从 lowcost 数组中找出权值最小的那个（U 集合到 U-V 集合中权值最小的那个边）
        for (j = 0; j < n; j++) {
            if (lowcost[i] < min) {
                min = lowcost[i];
                // 记录下目前为止找到的最小权值的下标到 k
                k = i;
            }
        }

        printf("%d %d %d\n", closest[k], k, min); //输出最小边
        lowcost[k] = 0;

        // 更新数组，新加入U的顶点到各终点之间的边是否权值更小
        for (j = 0; j < n; j++) {
            if (G.edges[k][j] < lowcost[j]) {
                lowcost[j] = G.edges[k][j];
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

void DisplayGraph(MGraph *g) {
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            if (g->edges[i][j] == INFINITY) {
                printf("* ");
            } else {
                printf("%d ", g->edges[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    MGraph *g = (MGraph *)malloc(sizeof(MGraph));

    CreateGraph(g);
    // DisplayGraph(g);
    MiniSpanTree_PRIM(*g, g->n, 0);

    getchar();
    getchar();
}
