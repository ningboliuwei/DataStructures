#include <stdio.h>
#include <stdlib.h>

// 问题 D: 【数据结构8-7】最短路径——Dijkstra算法
// ID：1649
// OJ PASSED
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
// 0 4 32
// 0 1 13
// 4 5 2
// 1 5 9
// 1 6 7
// 5 6 17
// 0 6 32
// 0 // 源点
// 1<-0 13
// 2<-0 8
// 3<-2<-0 13
// 4<-3<-2<-0 21
// 6<-1<-0 20
// PPT 上的例子
// 输入
// 7 10
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 1 2 13
// 1 3 8
// 3 4 5
// 4 5 6
// 5 6 2
// 2 6 9
// 2 7 7
// 6 7 17
// 1 7 32
// 1 5 30
// 1

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
// Dijkstra 算法求有向网G的某个顶点到其余顶点的最短路径
void ShortestPath_DIJ(MGraph G, int start) {
    // P[] 表示从源点（如 v0）到各顶点的最短路径上，此顶点的前一顶点的下标；若从起点到该顶点无路径，则设值为
    // -1；本数组用于从某个顶点开始，倒推到起点的每一条边（因为一条最短路径都是由若干条最短路径的“前缀”组成的），
    // 也就是说，往前递归地寻找离当前这个顶点最近的点
    int P[MAXVER];
    // 《D》可以理解为《DISTANCE》
    // D[] 存放当前找到的从源点（如 v0）到每个终点的最短路径长度，初始值为图中从源点到各个其他顶点的直接路径权值
    // 相当于 PRIM 算法程序中的 lowcost[]
    int D[MAXVER];
    // 是否已经找到了到 i 这个点的最短路径，如果找到，则 final[i] 记为 TRUE，否则记为 FALSE
    int final[MAXVER];
    int i, v, w, min, pre;

    // 初始化
    for (v = 0; v < G.vexnum; ++v) {
        // 初始化，FALSE 表示从起点 start 到顶点 v，还没有求出最短路径
        final[v] = FALSE;
        // D 初始值为从起点 start 到 v 点的直接路径的权值
        D[v] = G.adjlist[start][v];
        // 目前找到的从 start 到 v 的最短路径中，点 v 的前一个点，计入 P[v]; 若无直接路径，则 P[v] 为 0（若是 start 到
        // start，则记为“无直接路径”）
        if (v == startPos || G.adjlist[start][v] == INFINITY) {
            P[v] = -1;
        } else {
            P[v] = startPos;
        }
    }
    // 起点到自己的最短路径距离为 0
    D[start] = 0;

    // 对于起点，可以认为已经找到了最短路径
    final[start] = TRUE;

    for (i = 0; i < G.vexnum; ++i) {
        // min 就是找当前最短路径 D[] 中最小的那个（下一个被“拎起来”的）顶点
        min = INFINITY;
        // 选出从当前点（点 i/外层循环）到其他所有顶点中距离最近的那个点，并把其加入 U（找到最短路径的集合）
        for (w = 0; w < G.vexnum; ++w) {
            if (!final[w]) {
                if (D[w] < min) {
                    min = D[w];
                    v = w;
                }
            }
        }
        // v 顶点入选 U
        final[v] = TRUE;
        // 根据入选的 v 顶点修改 D[] 及 P[]
        for (w = 0; w < G.vexnum; ++w)
            // 逐渐更新 D[] 及 P[]
            if (!final[w]) {
                if (min + G.adjlist[v][w] < D[w]) {
                    D[w] = min + G.adjlist[v][w];
                    P[w] = v;
                }
            }
    }
    // 依次输出所有最短路径，具体思路看 P[]
    for (w = 0; w < G.vexnum; ++w) {
        if (w != start) {
            // 输出当前顶点
            printf("%d", w);
            pre = P[w];

            while (pre != -1) {
                printf("<-%d", pre);
                pre = P[pre];
            }

            printf(" %d\n", D[w]);
        }
    }
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
        // 最短路径默认无向图，把角对称给去掉
    }
}

int main() {
    MGraph *g = (MGraph *)malloc(sizeof(MGraph));

    CreateGraph(g);
    int start;

    scanf("%d", &start);
    ShortestPath_DIJ(*g, start);

    getchar();
    getchar();
}
