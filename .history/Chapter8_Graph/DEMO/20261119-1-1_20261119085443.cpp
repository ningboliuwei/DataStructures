#include <stdio.h>
#include <stdlib.h>

#define MAX_NODE_COUNT 10

typedef struct {
    char vexs[MAX_NODE_COUNT];
    int edges[MAX_NODE_COUNT][MAX_NODE_COUNT];
    // 顶点个数
    int n;
    // 边数
    int e;
} MGraph;

void CreateGraph(MGraph *g) {
    char vex1;
    char vex2;
    int weight;

    // 对邻接矩阵进行初始化
    for (int i = 0; i < MAX_NODE_COUNT; i++) {
        for (int j = 0; j < MAX_NODE_COUNT; j++) {
            g->edges[i][j] = 0;
        }
    }

    scanf("%d %d\n", &(g->n), &(g->e));

    for (int i = 0; i < g->n; i++) {
        char c;
        scanf("\n%c", &c);
        g->vexs[i] = c;
    }
}

void DisplayGraph(MGraph *g) {
}

int main() {
    MGraph *g = (MGraph *)malloc(sizeof(MGraph));
    CreateGraph(g);
    DisplayGraph(g);

    getchar();
    getchar();
}
