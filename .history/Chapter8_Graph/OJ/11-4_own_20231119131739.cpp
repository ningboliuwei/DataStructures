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
    // 第一步是选出从 U 集合中唯一的点（即起点）出发到 V-U 集合中，权值最小的那个边

    for (i = 0; i < n - 1; i++) {
        min = INFINITY;
        // 从 lowcost 数组中找出权值最小的那个（U 集合到 V-U 集合中权值最小的那个边）
        for (j = 0; j < n; j++) {
            if (lowcost[j] < min && lowcost[j] != 0) {
                min = lowcost[j];
                // 记录下目前为止找到的最小权值的下标到 k
                k = j;
            }
        }
        // 输出最小边（先选出从 U 到 U-V 中权值最小的那个边，k （从下标 0 遍历到 下标 n-1，k 是 V-U
        // 中的那一端）就是终点的下标，closest[j] 就是 U 中离第 j 个顶点距离最近的那个点，closest[k] 就是 U 中离第 k
        // 个顶点距离最近的那个点的下标（思想就是每加入一个新的顶点，先看看这个顶点到各个其他顶点的距离会不会比之前的其他所有点有更近的边，换句话说就是保证
        // closest 和 lowcost 这两个数组中保存的都是 U 到每个 V-U 中所有点距离最短的那个点（和边））
        printf("%d %d %d\n", closest[k] + 1, k + 1, min);
        // 设为 0，表示这个点在集合 U 中了
        lowcost[k] = 0;

        // 更新数组，判断加入 U 的顶点到各终点之间的边是否权值更小，如果更小，则将 lowcost
        // 数组中与某个顶点相关的元素改为新的权值； 将 closest
        // 数组中与某个顶点相关的元素改为新的下标（就是这个新加入的顶点的下标）
        for (j = 0; j < n; j++) {
            if (G.edges[k][j] < lowcost[j]) {
                lowcost[j] = G.edges[k][j];
                closest[j] = k;
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
    MiniSpanTree_PRIM(*g, g->n, 0);

    getchar();
    getchar();
}
