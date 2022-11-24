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

#define MAXVER 10
#define INFINITY 99999
#define TRUE 1
#define FALSE 0

typedef struct {
    char vexs[MAXVER];
    int adjlist[MAXVER][MAXVER];
    // 顶点数
    int vexnum;
    // 边数
    int e;
} MGraph;
// V1是源点
// Dijkstra算法求有向网G的v1顶点到其余顶点的最短路径
void ShortestPath_DIJ(MGraph G, int start) {
    // P[] 表示从源点（如
    // v0）到各终点的最短路径上，此顶点的前一顶点的序号；若从V0到某终点无路径，则用0作为其前一顶点的序号；有点类似于
    // PRIM 算法中的 closest 数组，即 U 中到 U-V 中的下标为 j （遍历时候有用）的顶点中，最近的那条边的起点
    int P[MAXVER];
    // D 可以理解为《DISTANCE》
    // D[] 存放当前找到的从源点（如 v0）到每个终点的最短路径长度，初始值为图中从源点到各个其他顶点的直接路径权值
    // 相当于 PRIM 算法程序中的 lowcost[]
    int D[MAXVER];
    int final[MAXVER]; //标识数组记录是否已求得最短路径
    int i, v, w, min, pre;

    // 初始化
    for (v = 0; v < G.vexnum; ++v) {
        // 初始化，0 表示从 start 到顶点 v，还没有求出最短路径
        final[v] = FALSE;
        // D 初始值为从 start 到 v 点的直接路径的权值
        D[v] = G.adjlist[start][v];
        if ()
            P[v] = ; //设置起点

        else
            P[v] = ;
    }
    // 起点到自己的最短路径距离为 0
    D[start] = 0;
    // 对于起点，可以认为已经找到了最短路径
    final[start] = TRUE;

    for (i = 1; i < G.vexnum; ++i) {
        // 寻找 final[] 为 FALSE 的 D[] 中最小值（即还没有找到最短路径的顶点（即 V-U 集合）中）
        min = INFINITY;

        for (w = 0; w < G.vexnum; ++w) //最小值->min，最小值的下标->v
        {
            if (G.adjlist[i][w] < min) {
                min = G.adjlist[i][w];
                // v 为目前找到的
                v = w;
            }
        }

        final[v] = TRUE; // v顶点入选

        for (w = 0; w < G.vexnum; ++w) //根据入选的v顶点修改D[ ]及p[ ]

            if (!final[w] && (min + G.adjlist[v][w] < D[w]))

            {}

    } //逐渐更新D[ ] 及P[ ]

    for (w = 1; w < G.vexnum; ++w) //依次输出所有最短路径,源点不输出

    {
        printf("%d", w);

        pre = P[w];

        while (pre != start)

        {} //输出

    } // for 输出结束

} // ShortestPath_DIJ

void CreateGraph(MGraph *g) {
    char vex1;
    char vex2;
    int weight;
    int pos1;
    int pos2;

    for (int i = 0; i < MAXVER; i++) {
        for (int j = 0; j < MAXVER; j++) {
            if (i == j) {
                g->adjlist[i][j] = 0;
            } else {
                g->adjlist[i][j] = INFINITY;
            }
        }
    }

    scanf("%d %d\n", &(g->vexnum), &(g->e));

    for (int i = 0; i < g->vexnum; i++) {
        char c;
        scanf("\n%c", &c);
        g->vexs[i] = c;
    }

    for (int i = 0; i < g->e; i++) {
        scanf("\n%c %c %d", &vex1, &vex2, &weight);

        for (pos1 = 0; pos1 < g->vexnum; pos1++) {
            if (g->vexs[pos1] == vex1) {
                break;
            }
        }

        for (pos2 = 0; pos2 < g->vexnum; pos2++) {
            if (g->vexs[pos2] == vex2) {
                break;
            }
        }

        g->adjlist[pos1][pos2] = weight;
        // 无向网要加下面一行（基于对角线对称）
        g->adjlist[pos2][pos1] = weight;
    }
}

int main() {
    MGraph *g = (MGraph *)malloc(sizeof(MGraph));

    CreateGraph(g);

    getchar();
    getchar();
}
