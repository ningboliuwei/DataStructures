#include <stdio.h>
#include <stdlib.h>

#define MAXVER 10
#define INFINITY

typedef int VertexType;

typedef struct {
    VertexType vertex[MAXVER];
    int adjList[MAXVER][MAXVER];
    // 顶点数
    int vexNum;
    // 边数
    int edgeNum;
} MGraph;

void CreateGraph(MGraph *g) {
    VertexType vex1;
    VertexType vex2;
    int pos1;
    int pos2;

    for (int i = 0; i < MAXVER; i++) {
        for (int j = 0; j < MAXVER; j++) {
            g->adjList[i][j] = 0;
        }
    }

    scanf("%d %d\n", &(g->vexNum), &(g->edgeNum));

    for (int i = 0; i < g->vexNum; i++) {
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

void ShortestPath_DIJ(MGraph G, int v1) // V1是源点
{ //用Dijkstra算法求有向网G的v1顶点到其余顶点的最短路径
    int P[MAXVER], D[MAXVER];
    int final[MAXVER]; //是否已求得最短路径
    int i, v, w, min, pre;
    for (v = 1; v <= G.vexnum; ++v) { // D[ ],final[ ],P[ ]初始化
        final[v] = FALSE;
        D[v] = G.adjlist[v1][v];
        if (D[v] < INFINITY)
            P[v] = 1;
        else
            P[v] = 0;
    }
    D[v1] = 0;
    final[v1] = TRUE; //源点v0相关数组初始化
    for (i = 2; i <= G.vexnum; ++i) {
        min = INFINITY;                 //寻找final[]=0的D[ ]中最小值
        for (w = 1; w <= G.vexnum; ++w) //最小值->min，最小值的下标->v
            if (!final[w] && D[w] < min) {
                v = w;
                min = D[w];
            }
        final[v] = TRUE;                // v顶点入选
        for (w = 1; w <= G.vexnum; ++w) //根据入选的v顶点修改D[ ]及p[ ]
            if (!final[w] && (min + G.adjlist[v][w] < D[w])) {
                D[w] = min + G.adjlist[v][w];
                P[w] = v;
            }
    }                               //逐渐更新D[ ] 及p[ ]
    for (w = 1; w <= G.vexnum; ++w) //依次输出所有最短路径
    {
        printf("%d", w);
        pre = P[w];
        if (pre == 0) {
            if (w == v1) {
                printf("    source point \n");
            } else {
                printf("    No Path \n");
            }
        } else {
            while (pre != v1) {
                printf("<--%d", pre);
                pre = P[pre];
            }
            printf("<--%d **** distance is:%d\n", v0, D[w]);
        } // else
    }     // for 输出结束
}
