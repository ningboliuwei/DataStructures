#include <stdio.h>
#include <stdlib.h>

// ���� D: �����ݽṹ8-7�����·������Dijkstra�㷨
// ID��1649
// OJ PASSED
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
// Dijkstra �㷨��������G��ĳ�����㵽���ඥ������·��
void ShortestPath_DIJ(MGraph G, int start) {
    // P[] ��ʾ��Դ�㣨��
    // v0��������������·���ϣ��˶����ǰһ������±ꣻ������㵽�ö�����·��������ֵΪ
    // -1�����������ڴ�ĳ�����㿪ʼ�����Ƶ�����ÿһ���ߣ���Ϊһ�����·�����������������·���ġ�ǰ׺����ɵģ���Ҳ����˵����ǰ�ݹ��Ѱ���뵱ǰ�����������ĵ�
    int P[MAXVER];
    // ��D����������Ϊ��DISTANCE��
    // D[] ��ŵ�ǰ�ҵ��Ĵ�Դ�㣨�� v0����ÿ���յ�����·�����ȣ���ʼֵΪͼ�д�Դ�㵽�������������ֱ��·��Ȩֵ
    // �൱�� PRIM �㷨�����е� lowcost[]
    int D[MAXVER];
    // �Ƿ��Ѿ��ҵ��˵� i ���������·��������ҵ����� final[i] ��Ϊ TRUE�������Ϊ FALSE
    int final[MAXVER];
    int i, v, w, min, pre;

    // ��ʼ��
    for (v = 0; v < G.vexnum; ++v) {
        // ��ʼ����0 ��ʾ�� start ������ v����û��������·��
        final[v] = FALSE;
        // D ��ʼֵΪ�� start �� v ���ֱ��·����Ȩֵ
        D[v] = G.adjlist[start][v];
        // Ŀǰ�ҵ��Ĵ� start �� v �����·���У��� v ��ǰһ���㣬���� P[v]; ����ֱ��·������ P[v] Ϊ 0������ start ��
        // start�����Ϊ����ֱ��·������
        if (v == start || G.adjlist[start][v] == INFINITY) {
            P[v] = -1;
        } else {
            P[v] = start;
        }
    }
    // ��㵽�Լ������·������Ϊ 0
    D[start] = 0;
    // ������㣬������Ϊ�Ѿ��ҵ������·��
    final[start] = TRUE;

    for (i = 0; i < G.vexnum; ++i) {
        // min �����ҵ�ǰ���·�� D[] ����С���Ǹ�����һ���������������ģ�����
        min = INFINITY;
        // ѡ���ӵ�ǰ�㣨�� i/���ѭ�������������ж����о���������Ǹ��㣬��������� U���ҵ����·���ļ��ϣ�
        for (w = 0; w < G.vexnum; ++w) {
            if (!final[w]) {
                if (D[w] < min) {
                    min = D[w];
                    v = w;
                }
            }
        }
        // v ������ѡ U
        final[v] = TRUE;
        // ������ѡ�� v �����޸� D[] �� P[]
        for (w = 0; w < G.vexnum; ++w)
            // �𽥸��� D[] �� P[]
            if (!final[w]) {
                if (min + G.adjlist[v][w] < D[w]) {
                    D[w] = min + G.adjlist[v][w];
                    P[w] = v;
                }
            }
    }
    // ��������������·��������˼·�� P[]
    for (w = 0; w < G.vexnum; ++w) {
        if (w != start) {
            // �����ǰ����
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
        // ���·��Ĭ������ͼ���ѽǶԳƸ�ȥ��
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
