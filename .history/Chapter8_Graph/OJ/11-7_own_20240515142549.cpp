#include <stdio.h>
#include <stdlib.h>

// 问题 E: 【数据结构8-5】最小生成树——Kruskal算法
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
// 或输入（PPT 63页）：
// 8 11
// a
// b
// c
// d
// e
// f
// g
// h
// a b 2
// a c 3
// b d 2
// c d 1
// d e 2
// d f 4
// e f 1
// g e 2
// f g 2
// g h 1
// f h 1
// 输出

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
    // 定义一个名为 vertexSets
    // 的数组，用于给每一个顶点设置其所属的集合，可以看成是这个顶点所属的连通分量的编号，用一个整数来表示。初始时，每个顶点分属不同的集合（连通分量）
    int vertexSets[MAX_VEX_COUNT];
    // 定义一个名为 edgeFlags 的数组，
    EdgeFlag edgeFlags[MAX_EDGE_COUNT];
    // 初始化 vexFlags 数组，设每个顶点都属于不同的集合（连通分量）
    for (int i = 0; i < G.n; i++) {
        vertexSets[i] = i;
    }
    int pos = 0;
    // 基于邻接矩阵，初始化 edgeFlags 数组（因为无向图是基于对角线对称的，所以内层循环列号 j 从行号 i，而不是 0 开始）
    for (int i = 0; i < G.n; i++) {
        for (int j = i; j < G.n; j++) {
            if (G.edges[i][j] > 0 && G.edges[i][j] < INFINITY) {
                edgeFlags[pos].u = i;
                edgeFlags[pos].v = j;
                edgeFlags[pos].weight = G.edges[i][j];
                edgeFlags[pos].flag = 0;
                pos++;
            }
        }
    }
    // 记录下当前已经找到的最小生成树中边的数目
    int foundCount = 0;
    // 如果还没有找满 顶点个数-1 条边，那么继续找
    while (foundCount < G.n - 1) {
        int min = INFINITY;
        // 找出所有边里权值最小，且 flag 为 0 的那条边，并将这条边在 edgeFlags 数组中的下标记录到变量 minEdgeIndex 中
        int minEdgeIndex = 0;
        for (int i = 0; i < G.e; i++) {
            if (edgeFlags[i].weight < min && edgeFlags[i].flag == 0) {
                min = edgeFlags[i].weight;
                minEdgeIndex = i;
            }
        }
        // 选中的这条权值最小边的起点下标保存到 startNodeIndex 中
        int startVertexIndex = edgeFlags[minEdgeIndex].u;
        // 选中的这条权值最小边的终点下标保存到 pos2 中
        int endVertexIndex = edgeFlags[minEdgeIndex].v;
        // 如果找到的权值最小边的起点与终点不属于同一个集合（连通分量），
        if (vertexSets[startVertexIndex] != vertexSets[endVertexIndex]) {
            // 那么将这条边的 flag 设为 1（表示选中了该条边作为最小生成树中的一条边）
            edgeFlags[minEdgeIndex].flag = 1;
            // 选中的边数 + 1
            foundCount++;
            // 权值最小边的起点所属的集合保存到 startVertexSet 中
            int startVertexSet = vertexSets[startVertexIndex];
            // 权值最小边的终点所属的集合保存到 endVertexSet 中
            int endVertexSet = vertexSets[endVertexIndex];
            // 遍历所有的顶点，并将权值最小边的终点及其连通分量中的所有顶点所属的集合设为与权值最小边的起点所属的集合一致，将这些点标记为属于同一个连通分量
            for (int i = 0; i < G.n; i++) {
                if (vertexSets[i] == endVertexSet) {
                    vertexSets[i] = startVertexSet;
                }
            }
        } else {
            edgeFlags[minEdgeIndex].flag = 2;
        }
    }

    // 遍历 edgeFlags 数组（相当于遍历了所有的边），输出所有 flag 为 1（即被选中的边）的信息，包括起点、终点与权值
    for (int i = 0; i < G.e; i++) {
        if (edgeFlags[i].flag == 1) {
            printf("%c %c %d\n", G.vexs[edgeFlags[i].u], G.vexs[edgeFlags[i].v], edgeFlags[i].weight);
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
