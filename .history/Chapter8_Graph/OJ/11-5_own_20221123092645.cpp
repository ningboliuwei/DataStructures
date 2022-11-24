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

#define MAXVER 10
#define INFINITY 99999
#define TRUE 1
#define FALSE 0

typedef struct {
    char vexs[MAXVER];
    int adjlist[MAXVER][MAXVER];
    // ������
    int vexnum;
    // ����
    int e;
} MGraph;
// V1��Դ��
// Dijkstra�㷨��������G��v1���㵽���ඥ������·��
void ShortestPath_DIJ(MGraph G, int start) {
    // P[] ��ʾ��Դ�㣨��
    // v0�������յ�����·���ϣ��˶����ǰһ�������ţ�����V0��ĳ�յ���·��������0��Ϊ��ǰһ�������ţ��е�������
    // PRIM �㷨�е� closest ���飬�� U �е� U-V �е��±�Ϊ j ������ʱ�����ã��Ķ����У�����������ߵ����
    int P[MAXVER];
    // D �������Ϊ��DISTANCE��
    // D[] ��ŵ�ǰ�ҵ��Ĵ�Դ�㣨�� v0����ÿ���յ�����·�����ȣ���ʼֵΪͼ�д�Դ�㵽�������������ֱ��·��Ȩֵ
    // �൱�� PRIM �㷨�����е� lowcost[]
    int D[MAXVER];
    int final[MAXVER]; //��ʶ�����¼�Ƿ���������·��
    int i, v, w, min, pre;

    // ��ʼ��
    for (v = 0; v < G.vexnum; ++v) {
        // ��ʼ����0 ��ʾ�� start ������ v����û��������·��
        final[v] = FALSE;
        // D ��ʼֵΪ�� start �� v ���ֱ��·����Ȩֵ
        D[v] = G.adjlist[start][v];
        if (v == start)
            P[v] = 0;
        else
            P[v] = start;
    }
    // ��㵽�Լ������·������Ϊ 0
    D[start] = 0;
    // ������㣬������Ϊ�Ѿ��ҵ������·��
    final[start] = TRUE;

    for (i = 1; i < G.vexnum; ++i) {
        // Ѱ�� final[] Ϊ FALSE �� D[] ����Сֵ������û���ҵ����·���Ķ��㣨�� V-U ���ϣ��е��±�Ϊ w
        // �Ķ�����Ȩֵ��С���Ǹ���
        min = INFINITY;

        for (w = 0; w < G.vexnum; ++w) {
            if (G.adjlist[i][w] < min) {
                // min Ϊ����������ĿǰΪֹ�ҵ��ӵ���С��Ȩֵ��ǰ���ǰ�棩
                min = G.adjlist[i][w];
                // v ΪĿǰ�ҵ����뵱ǰ�㣨�±�Ϊ i �Ķ��㣩������Ǹ�������±�
                v = w;
            }
        }
        // v ������ѡ U
        final[v] = TRUE;
        // ������ѡ�� v �����޸�D[] �� P[]
        for (w = 0; w < G.vexnum; ++w)
            // �𽥸���D[ ] ��P[ ]
            if (!final[w] && (min + G.adjlist[v][w] < D[w])) {
                D[w] = min + G.adjlist[v][w];
                P[v] = w;
            }
    }
    // ��������������·��,Դ�㲻���
    for (w = 1; w < G.vexnum; ++w) {
        // �����ǰ����
        printf("%d", w);
        pre = P[w];

        while (pre != start) {
            printf("<-%d", pre);
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
        // ������Ҫ������һ�У����ڶԽ��߶Գƣ�
        g->adjlist[pos2][pos1] = weight;
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
