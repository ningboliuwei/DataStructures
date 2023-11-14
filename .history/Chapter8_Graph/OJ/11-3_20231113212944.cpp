//
// Created by Liu Wei on 2018/11/25.
// 问题 A: 【数据结构8-3】图的遍历——DFS
// ID：1645
// OJ PASSED
// 输入数据：
// 8 10
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 3 7
// 4 8
// 5 8
// 6 8
// 7 8
// 输出结果：
// DFS 1 2 4 8 5 6 3 7

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10

typedef int VertexType;

typedef struct {
    // 顶点表
    VertexType vertex[MAXLEN];
    // 边表
    int edges[MAXLEN][MAXLEN];
    // 顶点数
    int n;
    // 边数
    int e;
} MGraph;

void CreateGraph(MGraph *g) {
    // 边的起点顶点
    VertexType vex1;
    // 边的终点顶点
    VertexType vex2;
    // 起点顶点在顶点表中的位置（下标）
    int pos1;
    // 终点顶点在顶点表中的位置（下标）
    int pos2;
    // 初始化边表
    for (int i = 0; i < MAXLEN; i++) {
        for (int j = 0; j < MAXLEN; j++) {
            g->edges[i][j] = 0;
        }
    }
    // 输入顶点数与边数
    scanf("%d %d\n", &(g->n), &(g->e));
    // 输入所有的顶点，并放入顶点表中
    for (int i = 0; i < g->n; i++) {
        VertexType c;
        scanf("\n%d", &c);
        g->vertex[i] = c;
    }
    // 遍历所有的边
    for (int i = 0; i < g->e; i++) {
        // 输入边的起点顶点与终点顶点
        scanf("\n%d %d", &vex1, &vex2);
        // 在顶点表中找到起点顶点所在的位置
        for (pos1 = 0; pos1 < g->n; pos1++) {
            if (g->vertex[pos1] == vex1) {
                break;
            }
        }
        // 在顶点表中找到终点顶点所在的位置
        for (pos2 = 0; pos2 < g->n; pos2++) {
            if (g->vertex[pos2] == vex2) {
                break;
            }
        }
        // 将邻接矩阵对应位置的元素设为 1
        g->edges[pos1][pos2] = 1;
        // 无向图邻接矩阵对称
        g->edges[pos2][pos1] = 1;
    }
}
// 深度遍历函数，参数 nodeIndex 为当前访问的顶点在顶点表中的下标，visted 为记录了哪些顶点已被访问过的数组
void DFSM(MGraph *g, int nodeIndex, int *visited) {
    // 输出当前顶点
    printf("%d ", g->vertex[nodeIndex]);
    // 将当前顶点设为“已访问”
    visited[nodeIndex] = 1;
    // 针对当前顶点的所有尚未被访问的邻接点，递归调用深度遍历函数
    for (int i = 0; i < g->n; i++) {
        if (g->edges[nodeIndex][i] == 1 && !visited[i]) {
            DFSM(g, i, visited);
        }
    }
}

void DFSTraverseM(MGraph *g) {
    // 生命 visted 数组，用于记录哪些顶点已被访问过
    int visited[g->n];
    // 初始化 visted 数组
    for (int i = 0; i < g->n; i++) {
        visited[i] = 0;
    }

    printf("DFS ");
    //
    for (int i = 0; i < g->n; i++) {
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
