//
// Created by Liu Wei on 2018/11/25.
// 问题 B: 【数据结构8-4】图的遍历——BFS

#include <stdio.h>
#include <stdlib.h>
#include <queue>             //引用头文件

using namespace std;

#define MAXLEN 10

typedef int VertexType;

typedef struct {
    VertexType vertex[MAXLEN];
    int edges[MAXLEN][MAXLEN];
    // 顶点数
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

    scanf("%d,%d\n", &(g->n), &(g->e));

    for (int i = 0; i < g->n; i++) {
        VertexType c;
        scanf("\n%d", &c);
        g->vertex[i] = c;
    }

    for (int i = 0; i < g->e; i++) {
        scanf("\n%d %d", &vex1, &vex2);

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
        // 无向图邻接矩阵对称
        g->edges[pos2][pos1] = 1;
    }
}

void BFSM(MGraph *g, int nodeIndex, int *visited) {

    queue<int> q;

    printf("%d ", g->vertex[nodeIndex]);
    visited[nodeIndex] = 1;

    q.push(nodeIndex);

    while (!q.empty()) {
        int currentIndex = q.front();
        q.pop();

        for (int i = 0; i < g->n; i++) {
            if (g->edges[currentIndex][i] == 1 && !visited[i]) {
                printf("%d ", g->vertex[i]);
                visited[i] = 1;
                q.push(i);
            }
        }
    }

    return;
}

void BFSTraverseM(MGraph *g) {
    int visited[g->n];

    for (int i = 0; i < g->n; i++) {
        visited[i] = 0;
    }

    printf("BFS ");
    for (int i = 0; i < g->n; i++) {
        if (!visited[i]) {
            BFSM(g, i, visited);
        }
    }
}

int main() {
    MGraph *g = (MGraph *) malloc(sizeof(MGraph));

    CreateGraph(g);
    BFSTraverseM(g);
}

