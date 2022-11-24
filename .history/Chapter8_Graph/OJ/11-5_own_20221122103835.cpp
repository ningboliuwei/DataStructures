#include <stdio.h>
#include <stdlib.h>

// 问题 D: 【数据结构8-7】最短路径——Dijkstra算法
// ID：1649
// 输入：
// 7 10
// 0
// 1
// 2
// 3
// 4
// 5
// 6
// 0 2 8
// 2 3 5
// 3 4 6
// 0 4 30
// 0 1 13
// 4 5 2
// 1 5 9
// 1 6 7
// 5 6 17
// 0 6 30
// 0 // 源点
// 1<-0 13
// 2<-0 8
// 3<-2<-0 13
// 4<-3<-2<-0 21
// 6<-1<-0 20

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

void ShortestPath_DIJ(MGraph G, int v1) // V1是源点

{ //用Dijkstra算法求有向网G的v1顶点到其余顶点的最短路径

    int P[MAXVER], D[MAXVER];

    int final[MAXVER]; //标识数组记录是否已求得最短路径

    int i, v, w, min, pre;

    for (v = 0; v < G.vexnum; ++v)

    {
        final[v] = ;

        D[v] = ;

        if ()
            P[v] = ; //设置起点

        else
            P[v] = ;

    } // D[ ],final[ ],P[ ]初始化

    D[v1] = 0;

    final[v1] = TRUE; //源点v0相关数组初始化

    for (i = 1; i < G.vexnum; ++i)

    {
        min = INFINITY; //寻找final[]=0的D[ ]中最小值

        for (w = 0; w < G.vexnum; ++w) //最小值->min，最小值的下标->v

        {}

        final[v] = TRUE; // v顶点入选

        for (w = 0; w < G.vexnum; ++w) //根据入选的v顶点修改D[ ]及p[ ]

            if (!final[w] && (min + G.adjlist[v][w] < D[w]))

            {}

    } //逐渐更新D[ ] 及P[ ]

    for (w = 1; w < G.vexnum; ++w) //依次输出所有最短路径,源点不输出

    {
        printf("%d", w);

        pre = P[w];

        while (pre != v1)

        {} //输出

    } // for 输出结束

} // ShortestPath_DIJ

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
