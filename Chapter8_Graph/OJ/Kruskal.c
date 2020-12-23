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
#define MAX_VERTEX_COUNT 6 //最大顶点数
#define MAX_INTEGER 32767  //表示最大整数，表示 ∞

typedef char VertexType; //每个顶点数据类型为字符型

typedef struct //邻接矩阵结构体
{
    VertexType vexs[MAX_VERTEX_COUNT]; //存放顶点元素的一维数组
    int edges[MAX_VERTEX_COUNT][MAX_VERTEX_COUNT]; //邻接矩阵二维数组
    int n; // 顶点数                                         //图的顶点数和边数
    int e; // 边数
} MGraph;

typedef struct //辅助数组结构体(候选最短边)
{
    VertexType adjvex; //候选最短边的邻接点
    int minWeight;     //候选最短边的权值
} ShortEdge;

int LocateVex(MGraph *G,
              VertexType v) //查找元素v在一维数组 Vertex[] 中的下标，并返回下标
{
    int i;

    for (i = 0; i < G->n; i++) {
        if (v == G->vexs[i]) {
            return i;
        }
    }

    printf("找不到该顶点!\n");
    return -1;
}

void CreateGraph(MGraph *G) //构建无向网（Undirected Network）
{
    int i, j;
    // 输入顶点数和边数
    printf("输入顶点个数和边数：\n");
    scanf("%d,%d", &G->n, &G->e);

    // 输入顶点元素
    printf("请输入顶点：\n");

    for (i = 0; i < G->n; i++) {
        getchar();
        scanf("%c", &(G->vexs[i]));
    }

    // 矩阵初始化
    for (i = 0; i < G->n; i++)
        for (j = 0; j < G->n; j++) {
            G->edges[i][j] = MAX_INTEGER;
        }

    // 构建邻接矩阵
    int n, m;
    VertexType v1, v2;
    int w; // v1->v2的权值

    printf("请输入边的信息和权值(例：a,b,15)：\n");
    for (i = 0; i < G->e; i++) {
        printf("输入第%d条边信息及权值：", i + 1);
        scanf(" %c,%c,%d", &v1, &v2, &w);
        n = LocateVex(G, v1); //获取v1所对应的在Vertex数组中的坐标
        m = LocateVex(G, v2); //获取v2所对应的在Vertex数组中的坐标

        if (n == -1 || m == -1) {
            printf("没有该顶点\n");
            return;
        }

        G->edges[n][m] = w;
        G->edges[m][n] = w; //无向网仅此处不同
    }
}

void PrintGraph(MGraph G) {
    int i = 0;
    int j = 0;

    printf("\n-------------------------------");
    printf("\n 邻接矩阵：\n\n");

    printf("\t ");

    for (i = 0; i < G.n; i++) {
        printf("\t%c", G.vexs[i]);
    }

    printf("\n");

    for (i = 0; i < G.n; i++) {
        printf("\t%c", G.vexs[i]);

        for (j = 0; j < G.n; j++) {

            if (G.edges[i][j] == MAX_INTEGER)
                printf("\t∞");
            else
                printf("\t%d", G.edges[i][j]);
        }
        printf("\n");
    }
}

typedef struct {
    int u; //起点
    int v; //终点
    int w; //权值
} Edge;

void Kruskal(Edge E[], int n, int e) // E[ ]已经按权值排好序
{
    int i, j, m1, m2, sn1, sn2, k;
    int vset[MAX_VERTEX_COUNT];

    for (i = 0; i < n; i++) {
        vset[i] = i; //集合数组初始化
    }

    k = 1;
    j = 0;

    while (k < n) {
        m1 = E[j].u;
        m2 = E[j].v;
        sn1 = vset[m1];
        sn2 = vset[m2];

        if (sn1 != sn2) {
            printf("边(%d，%d权为：%d\n", m1, m2, E[j].w);
            k++;
            for (i = 0; i < n; i++)
                if (vset[i] == sn2)
                    vset[i] = sn1;
        }

        j++;
    }
}

int main() {
    VertexType start;

    MGraph G;
    CreateGraph(&G);
    PrintGraph(G);

    printf("请输入起始点：");
    scanf(" %c", &start); //%c前面有空格
    MiniSpanTree_Prim(&G, start);

    return 0;
}