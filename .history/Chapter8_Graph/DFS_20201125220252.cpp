//
// Created by Liu Wei on 2018/11/25.
// �?�? A: 【数�?结构8-3】图的遍历——DFS

#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10

typedef int VertexType;

typedef struct {
    VertexType vertex[MAXLEN];
    int edges[MAXLEN][MAXLEN];
    // 顶点�?
    int n;
    // 边数
    int e;
} MGraph;

void CreateGraph(MGraph *g) {
    VertexType vex1;
    VertexType vex2;
    int pos1;
    int pos2;

    for (int i = 0; i < MAXLEN; i++) {
        for (int j = 0; j < MAXLEN; j++) {
            g->edges[i][j] = 0;
        }
    }

    printf("请输入边数与顶点数：");
    scanf("%d,%d\n", &(g->n), &(g->e));

    printf("请输入各顶点：\n");
    for (int i = 0; i < g->n; i++) {
        VertexType c;
        scanf("\n%d", &c);
        g->vertex[i] = c;
    }

    printf("请输入每条边对应的两�?顶点：\n");
    for (int i = 0; i < g->e; i++) {
        printf("请输入�??%d条边的顶点：", i + 1);
        scanf("\n%d,%d", &vex1, &vex2);

        for (pos1 = 0; pos1 < g->n; pos1++) {
            if (g->vertex[pos1] == vex1) {
                break;
            }
        }

        for (pos2 = 0; pos2 < g->n; pos2++) {
            if (g->vertex[pos2] == vex2) {
                break;
            }
        }

        g->edges[pos1][pos2] = 1;
        // 无向图邻接矩阵�?�称
        g->edges[pos2][pos1] = 1;
    }
}

void DFSM(MGraph *g, int nodeIndex, int *visited) {
    printf("%d ", g->vertex[nodeIndex]);
    visited[nodeIndex] = 1;

    for (int i = 0; i < g->n; i++) {
        if (g->edges[nodeIndex][i] == 1 && !visited[i]) {
            DFSM(g, i, visited);
        }
    }
}

void DFSTraverseM(MGraph *g) {
    int visited[g->n];

    for (int i = 0; i < g->n; i++) {
        visited[i] = 0;
    }

    printf("DFS ");
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
}
