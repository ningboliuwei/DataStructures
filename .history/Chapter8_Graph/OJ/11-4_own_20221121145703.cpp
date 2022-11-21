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
typedef struct {
    char vexs[MAX_VEX_COUNT];
    int edges[MAX_VEX_COUNT][MAX_VEX_COUNT];
    // 顶点数
    int n;
    // 边数
    int e;
} MGraph;

// void MiniSpanTree_PRIM(MGraph G, int n, int v)

// {
//     int lowcost[MAX_VEX_COUNT];

//     int closest[MAX_VEX_COUNT];

//     int i, j, k, min;

//     for (i = 0; i < n; i++)

//     {
//         lowcost[i] = ;

//         closest[i] = ;

//     } //数组初始化

//     for (i = 0; i < n - 1; i++)

//     {
//         min = INF;

//         for (j = 0; j < n; j++) //确定最小边

//         {}

//         printf(“边(% d, % d) 权为： % d\n”, closest[k], k, min); //输出最小边

//         lowcost[k] = 0;

//         for (j = 0; j < n; j++) //更新数组，新加入U的顶点到各终点之间的边是否权值更小

//         {}
//     }

// } // Min

void CreateGraph(MGraph *g) {
    char vex1;
    char vex2;
    int weight;
    int pos1;
    int pos2;

    for (int i = 0; i < MAX_VEX_COUNT; i++) {
        for (int j = 0; j < MAX_VEX_COUNT; j++) {
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
