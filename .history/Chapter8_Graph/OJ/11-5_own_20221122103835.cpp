#include <stdio.h>
#include <stdlib.h>

// ���� D: �����ݽṹ8-7�����·������Dijkstra�㷨
// ID��1649
// ���룺
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
// 0 // Դ��
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
    // ������
    int n;
    // ����
    int e;
} MGraph;

void ShortestPath_DIJ(MGraph G, int v1) // V1��Դ��

{ //��Dijkstra�㷨��������G��v1���㵽���ඥ������·��

    int P[MAXVER], D[MAXVER];

    int final[MAXVER]; //��ʶ�����¼�Ƿ���������·��

    int i, v, w, min, pre;

    for (v = 0; v < G.vexnum; ++v)

    {
        final[v] = ;

        D[v] = ;

        if ()
            P[v] = ; //�������

        else
            P[v] = ;

    } // D[ ],final[ ],P[ ]��ʼ��

    D[v1] = 0;

    final[v1] = TRUE; //Դ��v0��������ʼ��

    for (i = 1; i < G.vexnum; ++i)

    {
        min = INFINITY; //Ѱ��final[]=0��D[ ]����Сֵ

        for (w = 0; w < G.vexnum; ++w) //��Сֵ->min����Сֵ���±�->v

        {}

        final[v] = TRUE; // v������ѡ

        for (w = 0; w < G.vexnum; ++w) //������ѡ��v�����޸�D[ ]��p[ ]

            if (!final[w] && (min + G.adjlist[v][w] < D[w]))

            {}

    } //�𽥸���D[ ] ��P[ ]

    for (w = 1; w < G.vexnum; ++w) //��������������·��,Դ�㲻���

    {
        printf("%d", w);

        pre = P[w];

        while (pre != v1)

        {} //���

    } // for �������

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
        // ������Ҫ������һ�У����ڶԽ��߶Գƣ�
        g->edges[pos2][pos1] = weight;
    }
}

int main() {
    MGraph *g = (MGraph *)malloc(sizeof(MGraph));

    CreateGraph(g);
    printf("��С������\n");
    MiniSpanTree_PRIM(*g, g->n, 0);

    getchar();
    getchar();
}
