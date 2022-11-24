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
void ShortestPath_DIJ(MGraph G, int v1) {
    int P[MAXVER];
    int D[MAXVER];
    int final[MAXVER]; //标识数组记录是否已求得最短路径
    int i, v, w, min, pre;

    // 初始化
    for (v = 0; v < G.vexnum; ++v)

    {
        final[v] = ;

        D[v] = ;

        if ()
            P[v] = ; //设置起点

        else
            P[v] = ;
    }

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
