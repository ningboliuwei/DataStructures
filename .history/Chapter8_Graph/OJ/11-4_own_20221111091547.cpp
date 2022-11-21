#include <stdio.h>
#include <stdlib.h>

/*
输入：
6,10
1
2
3
4
5
6
1,2,6
1,3,1
1,4,5
2,3,5
2,5,3
3,4,5
3,5,6
3,6,4
4,6,2
5,6,6

1（起始点）

输出结果：
1->3,1
3->6,4
6->4,2
3->2,5
2->5,3
*/
//最大顶点数
#define MAX_VERTEX_COUNT 10
//表示最大整数，表示 ∞
#define MAX_INTEGER 32767

//每个顶点数据类型为字符型
typedef char VertexType;
//邻接矩阵结构体
typedef struct {
    // 存放顶点元素的一维数组
    VertexType vexs[MAX_VERTEX_COUNT];
    // 邻接矩阵二维数组
    int edges[MAX_VERTEX_COUNT][MAX_VERTEX_COUNT];
    // 顶点数
    int n;
    // 边数
    int e;
} MGraph;

//辅助数组结构体(候选最短边)
typedef struct {
    //候选最短边的邻接点
    VertexType adjvex;
    //候选最短边的权值
    int minWeight;
} ShortEdge;

// 查找元素v在一维数组 Vertex[] 中的下标，并返回下标
int LocateVex(MGraph *G, VertexType v) {
    int i;

    for (i = 0; i < G->n; i++) {
        if (v == G->vexs[i]) {
            return i;
        }
    }

    printf("找不到该顶点!\n");
    return -1;
}
// 构建无向网（Undirected Network）
void CreateGraph(MGraph *G) {
    int i = 0;
    int j = 0;
    scanf("%d %d", &G->n, &G->e);

    for (i = 0; i < G->n; i++) {
        scanf("%c", &(G->vexs[i]));
    }

    // 矩阵初始化
    for (i = 0; i < G->n; i++)
        for (j = 0; j < G->n; j++) {
            G->edges[i][j] = MAX_INTEGER;
        }

    // 构建邻接矩阵
    int n = 0;
    int m = 0;
    VertexType v1;
    VertexType v2;
    int weight; // v1->v2的权值

    for (i = 0; i < G->e; i++) {
        scanf("%c %c %d", &v1, &v2, &weight);
        // 获取 v1 所对应的在Vertex数组中的写下标
        n = LocateVex(G, v1);
        // 获取v2所对应的在Vertex数组中的下标
        m = LocateVex(G, v2);

        G->edges[n][m] = weight;
        // 无向网需要下一行代码
        G->edges[m][n] = weight;
    }
}

int GetMinimalWeightVertex(MGraph *G, ShortEdge *shortEdge) {
    int i = 0;
    int j = 0;
    int min = 0;
    int location = 0;

    min = MAX_INTEGER;
    for (i = 1; i < G->n; i++) {
        if (min > shortEdge[i].minWeight && shortEdge[i].minWeight != 0) {
            min = shortEdge[i].minWeight;
            location = i;
        }
    }
    return location;
}

void MiniSpanTree_Prim(MGraph *G, VertexType startVex) {
    int i = 0;
    int j = 0;
    int k = 0;

    ShortEdge shortEdge[MAX_VERTEX_COUNT];

    // 1. 处理起始点start
    k = LocateVex(G, startVex);

    for (i = 0; i < G->n; i++) {
        shortEdge[i].adjvex = startVex; // 候选最短边邻接点等于起点
        shortEdge[i].minWeight = G->edges[k][i];
    }

    shortEdge[k].minWeight = 0; // minWeight为0表示该顶点属于U集合

    // 2.处理后续结点
    for (i = 0; i < G->n - 1; i++) //对集合U，去找最短路径的顶点
    {
        k = GetMinimalWeightVertex(G, shortEdge); //找最短路径的顶点

        printf("%c->%c,%d\n", shortEdge[k].adjvex, G->vexs[k],
               shortEdge[k].minWeight); //输出找到的最短路径顶，及路径权值
        shortEdge[k].minWeight = 0;     //将找到的最短路径顶点加入集合U中

        for (j = 0; j < G->n; j++) // U中加入了新节点，可能出现新的最短路径，故更新shortedge数组
        {
            if (G->edges[k][j] < shortEdge[j].minWeight) //有更短路径出现时，将其替换进shortedge数组
            {
                shortEdge[j].minWeight = G->edges[k][j];
                shortEdge[j].adjvex = G->vexs[k];
            }
        }
    }
}

int main() {
    VertexType start;

    MGraph G;
    CreateGraph(&G);
    MiniSpanTree_Prim(&G, start);

    return 0;
}