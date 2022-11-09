//
// Created by Liu Wei on 2018/11/25.
// 题号：1643
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
    char vexs[MAXLEN];
    int edges[MAXLEN][MAXLEN];
    // 顶点数
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
