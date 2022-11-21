#include <stdio.h>
#include <stdlib.h>

// ���� E: �����ݽṹ8-5����С����������Prim�㷨
// ID��1647
// ���룺
// 6 10
// 1
// 2
// 3
// 4
// 5
// 6
// 1 2 6
// 1 3 1
// 1 4 5
// 2 3 5
// 3 4 5
// 2 5 3
// 3 5 6
// 5 6 6
// 3 6 4
// 4 6 2
// �����
// ��С������
// 1 3 1
// 3 6 4
// 6 4 2
// 3 2 5
// 2 5 3

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

void MiniSpanTree_PRIM(MGraph G, int n, int v) {
    // lowcost �������ڴ�� U �����е����� i���±꣩Ȩֵ��С��·����̣����Ǹ�����ıߵ�Ȩֵ
    int lowcost[MAX_VEX_COUNT];
    // closest �������ڴ�� U �����е����� i���±꣩Ȩֵ��С��·����̣����Ǹ�������±�
    int closest[MAX_VEX_COUNT];
    int i;
    int j;
    int k;
    int min;

    for (i = 0; i < n; i++) {
        // lowcost ��ʼֵΪ��㵽�������Ȩֵ
        lowcost[i] = G.edges[v][i];
        // close ��ʼֵΪ�����±꣨�β� v��
        closest[i] = v;
    }
    // ��һ����ѡ���� U ������Ψһ�ĵ㣨����㣩������ U-V �����У�Ȩֵ��С���Ǹ���

    for (i = 0; i < n - 1; i++) {
        min = INFINITY;
        // �� lowcost �������ҳ�Ȩֵ��С���Ǹ���U ���ϵ� U-V ������Ȩֵ��С���Ǹ��ߣ�
        for (j = 0; j < n; j++) {
            if (lowcost[i] < min) {
                min = lowcost[i];
                // ��¼��ĿǰΪֹ�ҵ�����СȨֵ���±굽 k
                k = i;
            }
        }

        printf("%d %d %d\n", closest[k], k, min); //�����С��
        lowcost[k] = 0;

        // �������飬�¼���U�Ķ��㵽���յ�֮��ı��Ƿ�Ȩֵ��С
        for (j = 0; j < n; j++) {
            if (G.edges[k][j] < lowcost[j]) {
                lowcost[j] = G.edges[k][j];
            }
        }
    }

} // Min

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

void DisplayGraph(MGraph *g) {
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            if (g->edges[i][j] == INFINITY) {
                printf("* ");
            } else {
                printf("%d ", g->edges[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    MGraph *g = (MGraph *)malloc(sizeof(MGraph));

    CreateGraph(g);
    // DisplayGraph(g);
    MiniSpanTree_PRIM(*g, g->n, 0);

    getchar();
    getchar();
}
