//
// Created by Liu Wei on 2018/11/25.
// 题号：1643
// OJ PASSED
// 输入顶点和边，创建无向网的邻接矩阵
// 输入
// 3 2
// a
// b
// c
// a b 1
// b c 2

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10
typedef struct {
    // 顶点集合
    char vexs[MAXLEN];
    // 邻接矩阵（二维数组）
    int edges[MAXLEN][MAXLEN];
    // 顶点数
    int n;
    // 边数
    int e;
} MGraph;

void CreateGraph(MGraph *g) {
    // 边的起点
    char vex1;
    // 边的终点
    char vex2;
    // 边的权值
    int weight;
    // 边的起点在顶点集合中的位置（下标）
    int pos1;
    // 边的终点在顶点集合中的位置（下标）
    int pos2;

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
            printf("%d ", g->edges[i][j]);
        }
        printf("\n");
    }
}

int main() {
    MGraph *g = (MGraph *)malloc(sizeof(MGraph));

    CreateGraph(g);
    DisplayGraph(g);

    getchar();
    getchar();
}
