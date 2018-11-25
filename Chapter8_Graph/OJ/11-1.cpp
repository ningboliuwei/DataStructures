//
// Created by Liu Wei on 2018/11/25.
// 输入顶点和边，创建无向网的邻接矩阵

#include <stdio.h>

#define MAXLEN 10
typedef struct {
    char vexs[MAXLEN];
    int edges[MAXLEN][MAXLEN];
    // 顶点数
    int n;
    // 边数
    int e;
} MGraph;

void CreateGraph(MGraph g) {
    char vex1;
    char vex2;
    char weight;
    int pos1;
    int pos2;

    scanf("%d %d", &(g.n), &(g.e));

    for (int i = 0; i < g.n; i++) {
        scanf("\n%c", &g.vexs[i]);
    }

    for (int i = 0; i < g.e; i++) {
        scanf("\n");
        scanf("%c", &vex1);
        scanf(" ");
        scanf("%c", &vex2);
        scanf(" ");
        scanf("%d", &weight);

        for (pos1 = 0; pos1 < g.n; pos1++) {
            if (g.vexs[pos1] == vex1) {
                break;
            }
        }

        for (pos2 = 0; pos2 < g.n; pos2++) {
            if (g.vexs[pos2] == vex2) {
                break;
            }
        }

        g.edges[pos1][pos2] = weight;
    }
}

void DisplayGraph(MGraph g) {
    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++) {
            printf("%d", g.edges[i][j]);
        }
        printf("\n");
    }
}

int main() {
    MGraph g;

    CreateGraph(g);
    DisplayGraph(g);
}

